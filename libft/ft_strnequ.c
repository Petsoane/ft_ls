/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strneu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 10:09:05 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/21 09:40:50 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int size1;
	int size2;

	size1 = 0;
	size2 = 0;
	while (*s1 && n != 0)
	{
		if (*s1++ != *s2++)
			return (0);
		n--;
	}
	return (1);
}
