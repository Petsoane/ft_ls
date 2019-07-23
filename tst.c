/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 08:34:51 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/23 08:57:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	char *name;

	if (ac != 2)
		name =strdup(".");
	else
		name = av[1];
	struct stat info;

	if (lstat(name, &info) == -1)
		puts("There is an error with the file");
	else if (S_ISDIR(info.st_mode))
		puts("This is a directory");
	return (0);
}
