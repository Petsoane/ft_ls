/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:04:15 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/28 14:13:51 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *str)
{
	char	*out;
	char	curr;
	int		i;
	int		is_start;

	i = 0;
	is_start = 1;
	out = (char *)malloc(ft_strlen(str) + 1);
	if (!out)
		return (NULL);
	while (*str)
	{
		curr = *str;
		if ((curr == '\n' || curr == ' ' || curr == '\t') && is_start == 1)
		{
			str++;
			continue;
		}
		is_start = 0;
		out[i++] = *str++;
	}
	i--;
	while (i != 0 && (out[i] == ' ' || out[i] == '\t' || out[i] == '\n'))
		i--;
	out[i + 1] = '\0';
	return (out);
}
