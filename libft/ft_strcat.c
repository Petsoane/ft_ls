/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:21:33 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/26 13:15:34 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dst, char const *src)
{
	int i;

	i = 0;
	while (dst[i])
		i++;
	while (*src)
	{
		dst[i++] = *src++;
	}
	dst[i] = '\0';
	return (dst);
}
