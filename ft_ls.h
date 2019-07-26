/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/07/25 16:01:14 by lpetsoan         ###   ########.fr       */
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
# include "macros.h"

typedef struct s_flags
{
	int recurse : 1;
}				t_flags;

typedef struct s_file
{
	char *name;
	struct s_file *next;
}	t_file;

void	print_contents(t_file *file);
void	add_node(t_file **head, struct dirent *file);
void	ft_ls(char *name);
void	clean_list(t_file *file);
void	SortedInsert(t_file **head,  t_file *newNode);
#endif
