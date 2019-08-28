/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:37:35 by event             #+#    #+#             */
/*   Updated: 2019/08/28 12:39:28 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_contents(t_file *head, t_flags *flags)
{
	int i;

	i = 1;
	if (flags->p_long)
		print_long(head, flags);
	else
		print_short(head, flags);
}

void	print_short(t_file *head, t_flags *flags)
{
	int i;
	i = 1;
	while (head != NULL)
	{
		if (head->name[0] == '.' && !flags->p_all)
		{
			head = head->next;
			continue;
		}
		print_form(IS_DIR_SHORT, head->name);
		if (i % 5 == 0)
		{
			print_form("\n");
			i = 1;
		}
		i++;
		head = head->next;
	}
}

void	print_long(t_file *head, t_flags *flags)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		if (head->name[0] == '.' && !flags->p_all)
		{
			head = head->next;
			continue;
		}
		print_perms(head->perms, head->is_dir);
		print_form(IS_DIR_FORM, head->links, head->u_name,
			head->g_name, head->mod_time, head->name);
		i++;
		head = head->next;
	}
}
