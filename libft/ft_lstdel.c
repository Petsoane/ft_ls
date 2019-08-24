/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:48:42 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/24 13:22:00 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **node, void (*del)(void *, size_t len))
{
	t_list	**prev;

	prev = NULL;
	while (!(*node))
	{
		del((*node)->data, (*node)->d_size);
		*prev = (*node);
		(*node) = (*node)->next;
		free(*prev);
		*prev = NULL;
	}
	*prev = NULL;
}
