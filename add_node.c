/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/28 16:48:14 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_node(t_file **h, struct dirent *file, t_flags *flags,
			char *basepath)
{
	t_file		*new_node;
	struct stat	info;

	/* Create a new node with basic information*/
	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	ft_strcpy(new_node->name, file->d_name);
	new_node->time = info.st_mtimespec.tv_sec;
	create_path(new_node->path, basepath, file->d_name);
	lstat(new_node->path, &info);
	if (S_ISDIR(info.st_mode))
		new_node->is_dir = 1;
	// check if the long flag was set.
	if (flags->p_long)
	{
		get_long_info(new_node, info);
	}
	if (flags->rev)
		sorted_insert(h, new_node, &descend_sort);
	else if (flags->t_sort && flags->rev)
		sorted_insert(h, new_node, &descend_t_sort);
	else if (flags->t_sort)
		sorted_insert(h, new_node, &ascend_t_sort);
	else
		sorted_insert(h, new_node, &ascend_sort);
}

/*
** These functions will be used to control the sortinh
** of the list respectully.
*/

int			ascend_sort(t_file *old, t_file *new)
{
	if (ft_strcmp(old->name, new->name) <= 0)
		return (1);
	return (0);
}

int			descend_sort(t_file *old, t_file *new)
{
	return (!(ascend_sort(old, new)));
}

int			ascend_t_sort(t_file *old, t_file *new)
{
	int ret;

	if ((ret = check_month(old, new)) != -1)
	{
		return (ret);
	}
	else if ((ret = check_date(old, new))  != -1)
	{
		return (ret);
	}
	else if ((ret = check_hours(old, new)) != -1)
	{
		return (ret);
	}
	else if ((ret = check_min(old, new)) != -1)
	{
		return (ret);
	}

	return (0);
}

int			descend_t_sort(t_file *old, t_file *new)
{
	return (!ascend_t_sort(old, new));
}
