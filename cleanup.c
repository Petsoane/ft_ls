/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:19:22 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/26 12:38:38 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	clean_list(t_file *head)
{
	t_file *prev;

	while (head->next != NULL)
	{
		prev = head;
		head = head->next;
		free(prev);
	}
	free(head);
}
