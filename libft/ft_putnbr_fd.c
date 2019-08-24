/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:37:59 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/05/21 16:04:35 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int num, int fd)
{
	char ch;
	char sign;

	if (num < 0)
	{
		sign = '-';
		write(fd, &sign, 1);
		num = -num;
	}
	if (num < 10)
	{
		ch = (num % 10) + '0';
	}
	else
	{
		ch = (num % 10) + '0';
		ft_putnbr_fd(num / 10, fd);
	}
	write(fd, &ch, 1);
}
