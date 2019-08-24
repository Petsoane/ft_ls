/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/24 16:59:05 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


//void 	create_path(char *path, char *basePath, char *name);
void 	free_node(t_file **head);

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
			name = ft_strdup(av[i]);
			ft_ls(name, &flags);
			i++;
		}
	}
	return (0);
}

void	ft_ls(char *basePath, t_flags *flags)
{
	//puts(basePath);
	char			path[1000];
	DIR				*dir;
	t_file			*head;
	t_file			*tmp;
	struct dirent	*file;
	struct stat		info;

	head = NULL;
	if (!(dir = opendir(basePath)))
	{
		perror("Openning file:");
		return;
	}
	while ((file = readdir(dir)) != NULL)
		add_node(&head, file, flags, basePath);
	print_contents(head, flags);
	tmp = head;
	while (head != NULL && flags->recurse)
	{
		create_path(path, basePath, head->name);
		if (stat(head->path, &info) != -1)
			if (S_ISDIR(info.st_mode) && NOT_DOT && NOT_DOT_DOT)
			{
				if (flags->p_all == 0 && head->name[0] == '.')
				{
					head = head->next;
					continue;
				}
				printf("\n%s:\n", path);
				ft_ls(head->path, flags);
			}
		head = head->next;
	}
	closedir(dir);
	clean_list(tmp);
}
