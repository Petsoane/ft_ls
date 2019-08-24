/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 10:31:05 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/24 12:20:43 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list **node, void (*del)(void *, size_t len))
{
	del(&((*node)->data), (*node)->d_size);
	free(node);
	*node = NULL;
}
