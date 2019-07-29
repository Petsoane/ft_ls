/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:48:24 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/29 16:30:47 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void SortedInsert(t_file **head, t_file* newNode, int (*f)(char *s1, char *s2))
{
	t_file dummy;
	t_file* current = &dummy;
	dummy.next = *head;

	while (current->next != NULL && f(current->next->name, newNode->name))
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
	*head = dummy.next;
}