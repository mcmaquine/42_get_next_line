/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:32:22 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/05 10:35:00 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void test_read_from_file()
{
	char	*line;
	int		fdd;
	int		fd = open("testfile", O_RDONLY);
	int		fd2 = open("file2", O_RDONLY);

	fdd = fd;
	if (fdd > 2)
	{
		line = get_next_line(fdd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fdd);
			if (fdd == fd )
				fdd = fd2;
			else
				fdd = fd;
		}
		close(fd2);
		close(fd);
	}
}

void	read_from_input()
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

void	read_single_file()
{
	char	*line;
	int		fd = open("file2", O_RDONLY);

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

int	main(void)
{
	int	fd =  open("file1", O_RDONLY);
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