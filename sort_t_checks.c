/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/08/30 11:55:19 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	These funcitions are used as sub-functions for sorting with the t flag.
**	They are used to sort the contents by month, date, time.
*/

int			check_month(t_file *old, t_file *new)
{
	int			end;
	int			k;
	static char	nstr[255];
	static char	ostr[255];
	static char	*month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
								"Aug", "Sep", "Oct", "Nov", "Dec"};

	end = 0;
	while (old->mod_time[end] && old->mod_time[end] != ' ')
		end++;
	ft_strncpy(ostr, old->mod_time, end);
	ft_strncpy(nstr, new->mod_time, end);
	end = 0;
	k = 0;
	while (end < 12 && strcmp(ostr, month[end]) != 0)
		end++;
	while (k < 12 && strcmp(nstr, month[k]) != 0)
		k++;
	if (end > k)
		return (1);
	return (end == k ? -1 : 0);
}

int			check_date(t_file *old, t_file *new)
{
	int		end;
	int		count;
	char	num[255];
	char	n2[255];
	char	*tmp;

	end = 0;
	count = 0;
	tmp = old->mod_time;
	ft_strncpy(num, (tmp + 4), 2);
	tmp = new->mod_time;
	ft_strncpy(n2, (tmp + 4), 2);
	if (ft_atoi(num) > ft_atoi(n2))
	{
		return (1);
	}
	if (ft_atoi(num) == ft_atoi(n2))
	{
		return (-1);
	}
	return (0);
}

int			check_hours(t_file *old, t_file *new)
{
	char num[255];
	char n2[255];

	ft_strncpy(num, (old->mod_time + 7), 2);
	ft_strncpy(n2, (new->mod_time + 7), 2);
	if (ft_atoi(num) > ft_atoi(n2))
	{
		return (1);
	}
	if (ft_atoi(num) == ft_atoi(n2))
	{
		return (-1);
	}
	return (0);
}

int			check_min(t_file *old, t_file *new)
{
	char num[255];
	char n2[255];

	ft_strncpy(num, (old->mod_time + 10), 2);
	ft_strncpy(n2, (new->mod_time + 10), 2);
	if (ft_atoi(num) > ft_atoi(n2))
	{
		return (1);
	}
	if (ft_atoi(num) == ft_atoi(n2))
	{
		return (-1);
	}
	return (0);
}
