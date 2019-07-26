/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:39:41 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/25 16:01:05 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	parse_flags(int ac, char **av, t_flags * flags)
{
	int i;
	int j;
	char *temp;

	i = 1;
	j = 0;
	while (i < ac)
	{
		temp = av[1];
		if (*temp == '-')
		{
			temp++;
			while (*temp)
			{
				if (*temp == RECUR)
					flags->recurse = 1;
				else
				{
					perror("Invalid flag specifi");
					exit(0);
				}
				temp++;
			}
		}
		else
			break;
	}
}
