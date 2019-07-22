/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/07/22 16:20:07 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int main(int ac, char **av)
{
    char    *name;
    
	if (ac == 2){
        name = strdup(av[1]);
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
	//char newPath[10000];

	head = NULL;
	
	// open the directry.
	dir = opendir(basePath);
	if (!dir )
		printf("Some error heappend");
	while ((file = readdir(dir)) != NULL)
	{
		add_node(&head, file);
	}
	print_contents(head);
	puts("");
	closedir(dir);
}
