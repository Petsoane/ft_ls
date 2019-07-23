/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:46:34 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/23 10:13:21 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* This function adds a node to the list,
 * For now it just adds the node to start of 
 * list,
 */
void	add_node(t_file **head, struct dirent *file)
{
	t_file *new_node;

	new_node = (t_file *)malloc(sizeof(t_file) * 1);
	new_node->name = file->d_name;
	// check if the file is a directory;
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->next = NULL;
		return ;
	}
	new_node->next = *head;
	*head = new_node;
}
