/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:33:38 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/28 15:56:35 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t len)
{
	size_t i;
	size_t out;

	i = ft_strlen(dst);
	out = i + ft_strlen(src);
	while (*src && i < len - 1 && len != 0)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (out - 1);
}
