/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:41:11 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/28 12:39:18 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H
# define RECUR 'R'
# define ALL 'a'
# define LONG 'l'
# define REV 'r'
# define T_SORT 't'
# define FORM_COLOR "%d %s %s %s \033[1;35m%s\n\033[0m"
# define FORM "%d %s %s %s %s\n"
# define SHORT_COLOR "\033[1;35m%s\033[0m\t\t"
# define SHORT "%s\t\t"
# define NOT_DOT strcmp(head->name, ".") != 0
# define NOT_DOT_DOT ft_strcmp(head->name, "..") != 0
# define IS_DIR_SHORT head->is_dir == 1 ? SHORT_COLOR : SHORT
# define IS_DIR_FORM head->is_dir == 1? FORM_COLOR : FORM

#endif
