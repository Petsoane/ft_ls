/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/22 15:12:52 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** : create_path
** This function will create a new path for ls to follow.
*/
 void 	create_path(char *path, char *basePath, char *name)
{
	strcpy(path, basePath);
	if (basePath[strlen(basePath) - 1] != '/')
		strcat(path, "/");
	strcat(path, name);
}
