/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/22 18:03:18 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

void 	create_path(char *path, char *basePath, char *name);

int main(int ac, char **av)
{
	char			*name;
	int				i;
	static t_flags	flags;

	if (ac == 1)
	{
		parse_flags(ac, av, &flags);
		ft_ls(".", &flags);
		return (0);
	}
	i = 1;
	parse_flags(ac, av, &flags);
	while (i < ac && av[i][0] == '-')
		i++;
	if (i - ac == 0)
	{
		ft_ls(".", &flags);
	}
	else
	{
		while (i < ac)
		{
			name = strdup(av[i]);
			ft_ls(name, &flags);
			i++;
		}
	}
	return (0);
}

void	ft_ls(char *basePath, t_flags *flags)
{
	char			path[1000];
	DIR				*dir;
	t_file			*head;
	t_file			*tmp;
	struct dirent	*file;
	struct stat		info;

	head = NULL;
	if (!(dir = opendir(basePath)))
		return ;
	while ((file = readdir(dir)) != NULL)
		add_node(&head, file, flags, basePath);
	print_contents(head, flags);
	tmp = head;
	while (head != NULL && flags->recurse)
	{
		create_path(path, basePath, head->name);
		if (lstat(path, &info) != -1)
			if (S_ISDIR(info.st_mode) && strcmp(head->name, ".") != 0 &&
			strcmp(head->name, "..") != 0)
			{
				if (flags->p_all == 0 && head->name[0] == '.')
				{
					head = head->next;
					continue;
				}
				printf("\n%s:\n", path);
				ft_ls(path, flags);
			}
		head = head->next;
		bzero(path, 1000);
	}
	closedir(dir);
	clean_list(tmp);
}

/*
** : create_path
** This function will create a new path for ls to follow.
*/
void 	create_path(char *path, char *basePath, char *name)
{
	strcpy(path, basePath);
	if (basePath[strlen(basePath) - 1] != '/')
		strcat(path, "/");
	strcat(path, name);
}
