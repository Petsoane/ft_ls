/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:20:28 by event             #+#    #+#             */
/*   Updated: 2019/07/21 15:53:39 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int main(int ac, char **av)
{
    t_file  *head;
    char    *name;
    DIR     *dir;
	struct dirent *file;
	t_file	*tmp;

	head = (t_file *)malloc(sizeof(t_file) * 1);
	head->name = NULL;
	head->next = NULL;

    if (ac == 2){
        name = strdup(av[1]);
    }
    else
        name = (strdup("."));
    
	dir = opendir(name);
	while ((file = readdir(dir)) != NULL){
		if (head->name == NULL)
			head->name = file->d_name;
		else{
			tmp = (t_file *)malloc(sizeof(t_file) * 1);
			tmp->name = file->d_name;
			tmp->next = head;
			head = tmp;
		}

	}
	print_contents(head);
	return (0);
}
