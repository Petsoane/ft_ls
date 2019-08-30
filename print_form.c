/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:37:35 by event             #+#    #+#             */
/*   Updated: 2019/08/30 11:25:44 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		print_form(const char *form, ...)
{
	va_list		list;

	va_start(list, form);
	while (*form)
	{
		if (*form == '%')
		{
			++form;
			if (*form == 's' || *form == 'S')
			{
				ft_putstr(va_arg(list, char *));
			}
			else if (*form == 'd' || *form == 'D')
			{
				ft_putnbr(va_arg(list, int));
			}
		}
		else
			ft_putchar(*form);
		++form;
	}
	return (0);
}
