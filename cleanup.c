/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:19:22 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/23 11:06:07 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/* This funtion cleans up the contents if the program,
 * and frees the memory.
 */
void	clean_list(t_file *head)
{
	t_file *prev;

	while (head->next != NULL)
	{
		prev = head;
		head = head->next;
		free(prev);
		//free(prev);
	}
	free(head);
	//free(head);
}
