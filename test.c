/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 01:41:41 by lpetsoan          #+#    #+#             */
/*   Updated: 2019/07/06 05:55:20 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

void	print_dir(const char *);
int		print_tabs(const char *);


/* color macros */
void red()
{
	printf("\x1B[31m");
}
void green()
{
	printf("\x1B[32m");
}
void magenta()
{
	printf("\x1B[35m");
}
void reset()
{
	printf("\x1B[0m");
}
int main(int argc, char **argv)
{
	if (argc != 2)
    {
		perror("Please give me a filename");
		return (0);
    }

	print_dir(argv[1]);
	return (0);
}

void	print_dir(const char *basePath)
{
	char path[10000];
	DIR		*dir;
	struct dirent *node;
	int depth = 0;

	dir = opendir(basePath);
	if (!dir)
		return ;
	int i = -1;
	while ((node = readdir(dir)) != NULL)
	{
		i++;
		if (node->d_name[0] != '.')
		{
			depth = print_tabs(basePath);
			if (depth % (i + 4) == 0)
				magenta();
			else if(depth % (i + 7) == 0)
				red();
			printf("%s\t", node->d_name);
			usleep(1000);
			green();
			// construct a new base path.
			strcpy(path, basePath);
			strcat(path, "/");
			strcat(path, node->d_name);
			print_dir(path);
		}
	}
	closedir(dir);
}

// adding tree formating
int		print_tabs(const char *path)
{
	int count = 0;

	while (*path++)
	{
		if (*path == '/')
		{
			printf("\t-");
			count++;
		}
	}
	return (count);
}
