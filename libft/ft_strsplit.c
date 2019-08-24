/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:47:08 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/28 14:15:21 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_wordcount(char const *s, char c);
int		ft_wordlen(char const *s, char c);
char	*ft_strtrimc(char const *s, char c);

char	**ft_strsplit(char const *s, char c)
{
	char	**out;
	char 	*temp;
	int		i;
	int		j;

	j = 0;	
	i = 0;
	temp = ft_strtrimc(s, c);
	out = (char **)malloc(sizeof(char **) * ft_wordcount(temp, c));
	if (!out)
		return (NULL);
	while (*temp)
	{
		if (*temp != c)
		{
			out[i] = (char *)malloc(sizeof(char) * ft_wordlen(temp,c));
			if (!out[i])
				return (NULL);
			while (*temp && *temp != c)
			{
				out[i][j] = *temp++;
				j++;
			}
			out[i][j] ='\0';
			j = 0;
			i++;
		}
		temp++;
	}
	return (out);
}

int		ft_wordlen(char const *s, char c)
{
	int		w_len;

	w_len = 0;
	while (*s != c && *s)
	{
		s++;
		w_len++;
	}
	return (w_len);
}

int		ft_wordcount(char const *s, char c)
{
	int		w_count;

	if (!*s)
		return (0);
	w_count = 0;
	while (*s)
	{
		if (*s == c)
			w_count++;
		s++;
	}
	return (w_count + 1);
}

char	*ft_strtrimc(char const *str, char c)
{
	
	char	*out;
	char	curr;
	int		i;
	int 	is_start;
	int 	size;

	size = 0;
	i = 0;
	is_start = 1;
	while (str[size])
		size++;
	out = (char *)malloc(size);
	if (!out)
		return (NULL);
	while (*str)
	{
		curr = *str;
		if (curr == c && is_start == 1)
		{
			str++;
			continue;
		}
		is_start = 0;
		out[i++] = *str++;
	}
	i -= 1;
	while (i != 0 && out[i] == c)
		i--;
	out[i + 1] = '\0';
	return (out);
}	
