/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:48:24 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/26 12:56:55 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sorted_insert(t_file **head, t_file *new_node, int (*f)(t_file *s1,
					t_file *s2))
{
	t_file		dummy;
	t_file		*current;

	current = &dummy;
	dummy.next = *head;
	while (current->next != NULL && f(current->next, new_node))
		current = current->next;
	new_node->next = current->next;
	current->next = new_node;
	*head = dummy.next;
}
