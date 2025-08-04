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
/*
Clear the buff buf of size size
*/
static	void	buff_clear(char *buf, size_t size)
{
	while (size)
	{
		*buf = '\0';
		buf++;
		size--;
	}
}
/*
Return a string which its last char is '\n' terminatted with '\0'
*/
static	char	*get_line(char *buf, size_t s)
{
	char	*line;

	s++;
	line = (char *)malloc(sizeof(char) * (s + 1));
	line[s] = '\0';
	while(--s)
	{
		line[s] = buf[s];
	}
	*line = *buf;
	return (line);
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		c[BUFFER_SIZE];
	size_t		len;

	len = 0;
	buff_clear(c, sizeof(c));
	read_bytes = read(fd, &c[len], 1);
	while (c[len] != 10 && read_bytes > 0 && len < BUFFER_SIZE)
	{
		len++;
		read_bytes = read(fd, &c[len], 1);
	} 
	if (len == 0)
		return (NULL);
	return (get_line(c, len));
}

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

int	main()
{
	read_from_input();
}
