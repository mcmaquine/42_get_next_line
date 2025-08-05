/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/01 14:20:26 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		c[BUFFER_SIZE];
	size_t		len;
	char		*line;

	len = 0;
	line = NULL;
	ft_bzero(c, sizeof(c));
	read_bytes = read(fd, &c[len], 1);
	while (c[len] != 10 && read_bytes > 0)
	{
		len++;
		if (len >= BUFFER_SIZE)
		{
			line = join(line, c, len);
			ft_bzero(c, sizeof(c));
			len = 0;
		}
		read_bytes = read(fd, &c[len], 1);
	}
	if (!line && !len)
		return (NULL);
	return (join(line, c, len));
}
/*
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

int	main()
{
	read_single_file();
}
*/