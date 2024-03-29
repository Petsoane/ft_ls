/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/08/28 12:22:31 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_perms(mode_t perms, int is_dir)
{
	print_form((is_dir) ? "d" : "-");
	print_form((perms & S_IRUSR) ? "r" : "-");
	print_form((perms & S_IWUSR) ? "w" : "-");
	print_form((perms & S_IXUSR) ? "x" : "-");
	print_form((perms & S_IRGRP) ? "r" : "-");
	print_form((perms & S_IWGRP) ? "w" : "-");
	print_form((perms & S_IXGRP) ? "x" : "-");
	print_form((perms & S_IROTH) ? "r" : "-");
	print_form((perms & S_IWOTH) ? "w" : "-");
	print_form((perms & S_IXOTH) ? "x " : "- ");
}
