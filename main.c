/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/07/25 16:01:12 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

int main(int ac, char **av)
{
    char    *name;
	int		flags;
	static t_flags flags;

	if (ac == 2){
        name = strdup(av[]);
    }
    else
        name = (strdup("."));
	ft_ls(name);
	return (0);
}

void	ft_ls(char *basePath)
{
	t_file *head;
	DIR *dir;
	struct dirent *file;
	struct stat info;

	head = NULL;
	// open the directry.
	dir = opendir(basePath);
	if (!dir)
		return ;
	while ((file = readdir(dir)) != NULL)
	{
		add_node(&head, file);
	}
	print_contents(head);
	puts("");
	//closedir(dir);
	char path[1000];
	t_file *tmp = head;
	while (head != NULL)
	{
		// construct path
		strcpy(path, basePath);
		if (basePath[strlen(basePath) - 1] != '/')
			strcat(path, "/");
		strcat(path, head->name);
		// if File path is valid and file is a directory, call ls and list contents.
		if (stat(path, &info) != -1)
			if (S_ISDIR(info.st_mode) && strcmp(head->name, ".") != 0 && strcmp(head->name, "..") != 0)
			{
				printf("\n%s:\n", path);
				ft_ls(path);
			}
		head = head->next;
		bzero(path, 1000);
	}
	closedir(dir);
	clean_list(tmp);
}
