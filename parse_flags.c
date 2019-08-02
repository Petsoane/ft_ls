/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <lpetsoan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:39:41 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/08/02 14:23:49 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
 * parse_flags
 * This function parses the values within the given set of strings
 */
void	parse_flags(int ac, char **av, t_flags * flags)
{
	int i;
	int j;
	char *temp;

	i = 1;
	j = 0;
	while (i < ac)// loop through the whole set of strings
	{
		temp = av[i];
		if (*temp == '-')// check if the string is a flag.
		{
			if (*(temp + 1) == '\0')
			{
				perror("Invalid flag given");
				exit(1);
			}
			temp++;
			while (*temp)
			{// check each flag -in the list of flags.
				if (*temp == RECUR)
				{
					flags->recurse = 1;
				}
				else if (*temp == ALL)
				{
					flags->p_all = 1;
				}
				else if (*temp == LONG)
				{
					flags->p_long = 1;
				}
				else if (*temp == REV)
				{
					flags->rev = 1;
				}
				else if (*temp == T_SORT)
				{
					flags->t_sort = 1;
				}
				else
				{
					// if after finding an invalid flag stop the program.
					perror("Invalid flag givem:");
					exit(0);
				}
				temp++;
			}
		}
		else // if not a flag, stop checking for a flag.
			break;
		i++;
	}
}
