/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/08/28 16:48:17 by lpetsoan         ###   ########.fr       */
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
# include <stdarg.h>
# include "macros.h"
# include "libft/libft.h"

typedef struct		s_flags
{
	int				recurse : 1;
	int				p_all : 1;
	int				p_long : 1;
	int				rev : 1;
	int				t_sort : 1;
}					t_flags;

typedef struct		s_file
{
	int				is_dir;
	time_t			time;
	char			name[255];
	char			u_name[255];
	char			g_name[255];
	char			mod_time[255];
	char			path[1024];
	mode_t			perms;
	long			n_sec;
	int				links;
	int				size;
	struct s_file	*next;

}					t_file;

int					ascend_sort(t_file *s1, t_file *s2);
int					descend_sort(t_file *s1, t_file *s2);
int					ascend_t_sort(t_file *old, t_file *n);
int					descend_t_sort(t_file *o, t_file *n);
void				print_contents(t_file *file, t_flags *flags);
void				add_node(t_file **head, struct dirent *file, t_flags *flags,
					char *basepath);
void				ft_ls(char *name, t_flags *flags);
void				clean_list(t_file *file);
void				sorted_insert(t_file **head, t_file *new_node,
					int (*f)(t_file *s1, t_file *s2));
void				parse_flags(int ac, char **av, t_flags *flags);
void				print_perms(mode_t perms, int is_dir);
void				create_path(char *path, char *basepath, char *name);
void				get_long_info(t_file *new_node, struct stat info);
void				print_long(t_file *head, t_flags *flags);
void				print_short(t_file *head, t_flags *flags);
int					print_form(const char *form, ...);
int					check_month(t_file *old, t_file *new);
int					check_date(t_file *old, t_file *new);
int					check_hours(t_file *old, t_file *new);
int					check_min(t_file *old, t_file *new);

#endif
