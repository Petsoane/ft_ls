/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:39:41 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/26 13:15:33 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_flag(char flag, t_flags *flags)
{
	if (flag == RECUR)
		flags->recurse = 1;
	else if (flag == ALL)
		flags->p_all = 1;
	else if (flag == LONG)
		flags->p_long = 1;
	else if (flag == REV)
		flags->rev = 1;
	else if (flag == T_SORT)
		flags->t_sort = 1;
	else
	{
		perror("Invalid flag givem:");
		exit(0);
	}
}

void	parse_flags(int ac, char **av, t_flags *flags)
{
	int		i;
	char	*temp;

	i = 1;
	while (i < ac)
	{
		temp = av[i];
		if (*temp == '-')
		{
			if (*(temp + 1) == '\0')
			{
				perror("Invalid flag given");
				exit(1);
			}
			temp++;
			while (*temp)
			{
				add_flag(*temp, flags);
				temp++;
			}
		}
		else
			break ;
		i++;
	}
}
