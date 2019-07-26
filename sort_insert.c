/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:48:24 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/23 12:55:12 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void SortedInsert(t_file **head, t_file* newNode)
{
	t_file dummy;
	t_file* current = &dummy;
	dummy.next = *head;

	while (current->next != NULL && strcmp(current->next->name, newNode->name) <= 0)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
	*head = dummy.next;
}
