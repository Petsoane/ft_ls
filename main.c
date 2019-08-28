/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/28 12:42:13 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int ac, char **av)
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
		ft_ls(".", &flags);
	else
		while (i < ac)
		{
			name = ft_strdup(av[i]);
			ft_ls(name, &flags);
			i++;
		}
	return (0);
}

void		walk_path(t_file *head, char *basepath, t_flags *flags)
{
	struct stat		info;
	char			path[10000];

	while (head != NULL && flags->recurse)
	{
		create_path(path, basepath, head->name);
		if (stat(head->path, &info) != -1)
			if (S_ISDIR(info.st_mode) && NOT_DOT && NOT_DOT_DOT)
			{
				if (flags->p_all == 0 && head->name[0] == '.')
				{
					head = head->next;
					continue;
				}
				print_form("\n\n\033[1;34m%s:\033[0m\n", path);
				ft_ls(head->path, flags);
			}
		head = head->next;
		bzero(path, 10000);
	}
}

void		ft_ls(char *basepath, t_flags *flags)
{
	DIR				*dir;
	t_file			*head;
	struct dirent	*file;

	head = NULL;
	if (!(dir = opendir(basepath)))
	{
		perror("Openning file:");
		return ;
	}
	while ((file = readdir(dir)) != NULL)
		add_node(&head, file, flags, basepath);
	print_contents(head, flags);
	walk_path(head, basepath, flags);
	closedir(dir);
	clean_list(head);
}
