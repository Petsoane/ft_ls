/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/22 17:25:07 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int ascend_sort(t_file *s1, t_file *s2);
int descend_sort(t_file *s1, t_file *s2);
int ascend_t_sort(t_file *o, t_file *new);
int descend_t_sort(t_file *o, t_file *n);
void 	create_path(char *path, char *basePath, char *name)
{
	strcpy(path, basePath);
	if (basePath[strlen(basePath) - 1] != '/')
		strcat(path, "/");
	strcat(path, name);
}

void	add_node(t_file **head, struct dirent *file, t_flags *flags, char *basePath)
{
	t_file *new_node;
	char path[100000];
	struct stat info;
	struct passwd *u_info;
	struct group *g_info;

	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	strcpy(new_node->name, file->d_name);
	new_node->time = info.st_mtime;
	if (flags->p_long)
	{
		create_path(path, basePath, file->d_name);
		lstat(path, &info);
		g_info = getgrgid(info.st_gid);
		u_info = getpwuid(info.st_uid);
		new_node->perms = info.st_mode;
		new_node->links = info.st_nlink;
		strcpy(new_node->u_name, (u_info == NULL ? "error" : u_info->pw_name));
		strcpy(new_node->g_name, strdup(g_info == NULL ? "error" : g_info->gr_name));
		strcpy(new_node->mod_time, ctime(&info.st_mtime));
		new_node->mod_time[strlen(new_node->mod_time) - 1] = '\0';
	}
	if (flags->rev)
		SortedInsert(head, new_node, &descend_sort);
	else if (flags->t_sort && flags->rev)
		SortedInsert(head, new_node, &descend_t_sort);
	else if (flags->t_sort)
		SortedInsert(head, new_node, &ascend_t_sort);
	else
		SortedInsert(head, new_node, &ascend_sort);
}

/*
** These functions will be used to control the sortinh
** of the list respectully.
*/
int		ascend_sort(t_file *old, t_file *new)
{
	if (strcmp(old->name, new->name) <= 0)
		return (1);
	return (0);
}

int		descend_sort(t_file *old, t_file *new)
{
	return (!(ascend_sort(old, new)));
}

int		ascend_t_sort(t_file *old, t_file *new)
{
	if ((old->time - new->time) >= 0)
		return (1);
	return (0);
}

int		descend_t_sort(t_file *old, t_file *new)
{
	return (!ascend_t_sort(old,new));
}
