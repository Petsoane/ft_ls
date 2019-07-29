/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/29 16:49:52 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ascend_sort(char *s1, char *s2);
int descend_sort(char *s1, char *s2);

void	add_node(t_file **head, struct dirent *file, t_flags *flags)
{
	t_file *new_node;
	struct stat info;
	struct passwd *u_info;
	struct group *g_info;

	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	new_node->name = file->d_name;
	if (flags->p_long)
	{
		lstat(file->d_name, &info);
		g_info = getgrgid(info.st_gid);
		u_info = getpwuid(info.st_uid);
		new_node->perms = info.st_mode;
		new_node->links = info.st_nlink;
		new_node->u_name = u_info->pw_name;
		new_node->g_name = g_info->gr_name;
		new_node->mod_time = ctime(&info.st_mtime);
		new_node->mod_time[strlen(new_node->mod_time) - 2] = '\0';
	}
	if (flags->rev)
		SortedInsert(head, new_node, &descend_sort);
	else
		SortedInsert(head, new_node, &ascend_sort);
}

int ascend_sort(char *old, char *new)
{
	if (strcmp(old, new) <= 0)
		return (1);
	return (0);
}

int descend_sort(char *old, char *new)
{
	return (!ascend_sort(old, new));
}
