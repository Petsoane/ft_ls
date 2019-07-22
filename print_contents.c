/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:37:35 by event             #+#    #+#             */
/*   Updated: 2019/07/22 16:20:19 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_contents(t_file *head)
{
	int i;

	i = 1;
	while (head != NULL){
		printf("%s ", head->name);
		printf("%d\n", head->is_dir);
		if (i % 4 == 0)
			puts("");
		i++;
		head = head->next;
	}
}
