/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/26 12:42:30 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_long_info(t_file *new_node, struct stat info)
{
	struct passwd	*u_info;
	struct group	*g_info;

	new_node->n_sec = info.st_mtimespec.tv_nsec;
	g_info = getgrgid(info.st_gid);
	u_info = getpwuid(info.st_uid);
	new_node->perms = info.st_mode;
	new_node->links = info.st_nlink;
	ft_strcpy(new_node->u_name, (u_info == NULL ? "error" : u_info->pw_name));
	ft_strcpy(new_node->g_name,
		ft_strdup(g_info == NULL ? "error" : g_info->gr_name));
	ft_strcpy(new_node->mod_time, ctime(&info.st_mtime));
	new_node->mod_time[strlen(new_node->mod_time) - 1] = '\0';
}
