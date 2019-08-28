/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_t_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:31:02 by event             #+#    #+#             */
/*   Updated: 2019/08/28 16:47:54 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_month(t_file *old, t_file *new)
{
	int start;
	int end;
	char *tmp;
	static char nstr[255];
	static char ostr[255];
	static char *month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
								"Aug", "Sep", "Oct", "Nov", "Dec"};
	start = 0;
	end = 0;
	tmp = old->mod_time;
	while (tmp[end] && tmp[end] != ' ')
	{
		end++;
	}
	char *n_tmp = new->mod_time;
	ft_strncpy(ostr, tmp, end);
	ft_strncpy(nstr, n_tmp, end);
	int i = 0;
	int k = 0;
	while (i < 12 && strcmp(ostr, month[i] ) != 0)
	{
		i++;
	}
	while (k < 12 && strcmp(nstr, month[k] ) != 0)
	{
		k++;
	}
	if (i > k)
	{
		return (1);
	}
	if (i == k)
		return (-1);
	return (0);
}

int			check_date(t_file *old, t_file *new)
{
	int start;
	int end;
	int count;
	char num[255];
	char n2[255];
	char *tmp;
	// char *n_tmp;

	start = 0;
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
