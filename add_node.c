/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/23 14:39:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* This function adds a node to the list,
 * For now it just adds the node to start of
 * list,
 */
void	add_node(t_file **head, struct dirent *file, t_flags *flags)
{
	t_file *new_node;
	struct stat info;

	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	new_node->name = file->d_name;
	if (flags->p_long)
	{
		lstat(file->d_name, &info);
		new_node->perms = info.st_mode;
	}
	// insert the node in its correct position.
	SortedInsert(head, new_node);
}
