/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:37:35 by event             #+#    #+#             */
/*   Updated: 2019/07/23 10:17:26 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_file *head, t_flags *flags);
void	print_short(t_file *head, t_flags *flags);

void	print_contents(t_file *head, t_flags *flags)
{
	int i;

	i = 1;
	if (flags->p_long)
	{
		print_long(head, flags);
	}
	else
		print_short(head, flags);
}

void print_short(t_file *head, t_flags *flags)
{
	int i;

	i = 1;
	while (head != NULL){
		if (head->name[0] == '.' && !flags->p_all)
		{
			head = head->next;
			continue;
		}
		printf("%s\t     ", head->name);
		if (i % 4 == 0)
			puts("");
		i++;
		head = head->next;
	}
}
void 	print_long(t_file *head, t_flags *flags)
{
	int i;

	puts("Printing the long version");
	i = 0;
	while (head != NULL)
	{
		if (head->name[0] == '.' && !flags->p_all)
		{
			head = head->next;
			continue;
		}
		printf("%d %s\n", head->perms, head->name);
		if (i % 4 == 0)
			puts("");
		i++;
		head = head->next;
	}
}
