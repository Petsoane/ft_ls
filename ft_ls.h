/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/07/21 15:42:07 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>

typedef struct s_file
{
	char *name;
	struct s_file *next;
}	t_file;

void	print_contents(t_file *file);
#endif
