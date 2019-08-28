/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/26 12:40:06 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	create_path(char *path, char *basepath, char *name)
{
	ft_strcpy(path, basepath);
	if (basepath[ft_strlen(basepath) - 1] != '/')
		ft_strcat(path, "/");
	ft_strcat(path, name);
}
