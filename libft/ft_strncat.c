/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:26:24 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/27 08:09:00 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *dst, char const *src, size_t n)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	while (*src && n > 0)
	{
		dst[i++] = *src++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
