/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/30 11:32:49 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This functino is used as way to walk through all the directories
** given in the list.
*/

void		walk_through_list(int i, int ac, char **av, t_flags *flags)
{
	struct stat	info;
	char		*name;

	while (i < ac)
	{
		name = ft_strdup(av[i]);
		if (lstat(name, &info) != -1)
			if (S_ISDIR(info.st_mode))
				ft_ls(name, flags);
		free(name);
		i++;
	}
}

/*
**	This function is used to print information for all the files in the list.
*/

void		pre_check(int i, t_flags *flags, int ac, char **av)
{
	int				tmp;
	struct stat		info;
	t_file			new_node;

	tmp = i;
	while (tmp < ac)
	{
		if (lstat(av[tmp], &info) != -1 && !S_ISDIR(info.st_mode))
		{
			if (flags->p_long)
			{
				get_long_info(&new_node, info);
				print_perms(new_node.perms, 0);
				print_form(FORM, new_node.links, new_node.u_name,
				new_node.g_name, new_node.size, new_node.mod_time, av[tmp]);
			}
			else
				print_form(SHORT, av[tmp]);
		}
		else
			perror("Error: ");
		tmp++;
	}
	walk_through_list(i, ac, av, flags);
}

/*
**	This is the main hub where the flags get parsed and if errors the program
**	returns an error and stops running.
**	This is where the list function gets started out.
*/

int			main(int ac, char **av)
{
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
		pre_check(i, &flags, ac, av);
	return (0);
}

/*
**	This is function is where the -R flag is handled and the file structure
**	is 'walked'.
*/

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

/*
**	This is the main part of the listing, it's where the directory contents are
**	are stored and printed on the screen.
*/

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
