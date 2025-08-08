/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:32:22 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/07 10:22:49 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_fd(int fd)
{
	char	*line;

	if (fd > 2)
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
}
void	test_read_from_file(void)
{
	char	*line;
	int		fdd;
	int		fd2;
	int		fd;

	fd = open("testfile", O_RDONLY);
	fd2 = open("file2", O_RDONLY);
	fdd = fd;
	if (fdd > 2)
	{
		line = get_next_line(fdd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fdd);
			if (fdd == fd)
				fdd = fd2;
			else
				fdd = fd;
		}
		close(fd2);
		close(fd);
	}
}

void	read_from_input(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(0);
	}
}

void	read_single_file(void)
{
	int		fd;

	fd = open("file2", O_RDONLY);
	test_fd(fd);
}

void	read_unfinished_line(void)
{
	int		fd;

	fd = open("file1", O_RDONLY);
	test_fd(fd);
}

void	onechar(void)
{
	int		fd;

	fd = open("onechar.txt", O_RDONLY);
	test_fd(fd);
}

void	only_nl(void)
{
	int		fd;
	char	*line;

	fd = open("only_nl.txt", O_RDONLY);
	test_fd(fd);
}

void	_41_with_nl(void)
{
	int		fd;
	char	*line;

	fd = open("41_with_nl", O_RDONLY);
	test_fd(fd);
}

int	main(void)
{
	only_nl();
}
