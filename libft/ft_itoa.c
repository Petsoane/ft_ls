/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 11:41:42 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/28 14:26:05 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


char *	ft_strrev(char *s)
{
	char *start;
	char *end;
	char temp;

	start = s;
	while (*s)
		s++;
	end = s - 1;
	while (start != end)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return (s);
}

char	*ft_itoa(int num)
{
	char		*out;
	long		size;
	long		temp;
	int			i;

	i = 0;
	temp = num;
	size = 0;
	while (temp > 10)
	{
		size += 1;
		temp /= 10;
	}
	out = (char *)malloc(sizeof(char) * size + 1);
	if (!out)
		return (NULL);
	while (num > 10)
	{
		out[i++] = (num % 10) + (int)'0';
		num /= 10;
	}
	out[i] = num + '0';
	out[i + 1] = '\0';
	ft_strrev(out);
	return (out);
}
