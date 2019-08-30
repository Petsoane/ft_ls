/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:37:35 by event             #+#    #+#             */
/*   Updated: 2019/08/30 11:17:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	This function is used to display the files on the list.
**	It has two sub-functions that print the long format or the short form.
*/
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
			head->g_name, head->size, head->mod_time, head->name);
		i++;
		head = head->next;
	}
}
