/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/07/29 16:30:32 by lpetsoan         ###   ########.fr       */
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
# include <pwd.h>
# include <stdlib.h>
# include <grp.h>
# include <time.h>
# include "macros.h"

typedef struct s_flags
{
	int recurse : 1;
	int p_all : 1;
	int p_long : 1;
	int rev : 1;
}				t_flags;

typedef struct s_file
{
	char *name;
	char *u_name;
	char *g_name;
	char *mod_time;
	int perms;
	int links;
	struct s_file *next;
}	t_file;

void	print_contents(t_file *file, t_flags *flags);
void	add_node(t_file **head, struct dirent *file, t_flags *flags);
void	ft_ls(char *name, t_flags *flags);
void	clean_list(t_file *file);
void	SortedInsert(t_file **head,  t_file *newNode, int (*f)(char *s1, char *s2));
void	parse_flags(int ac, char **av, t_flags *flags);

#endif
