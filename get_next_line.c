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

/*static size_t count_char(char *buf)
{
	size_t cnt;

	cnt = 0;
	while(*buf && *buf != '\n')
	{
		cnt++;
		buf++;
	}
	return (cnt);
}

static	void	buff_clear(char *buf)
{
	while (*buf)
	{
		*buf = '\0';
		buf++;
	}
}*/

static	char	*get_line(char *buf, size_t s)
{
	char	*line;

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
	read_bytes = read(fd, &c[len], 1);
	while (c != '\n' && read_bytes > 0 && len < BUFFER_SIZE)
	{
		len++;
		read_bytes = read(fd, &c[len], 1);
	}
	
	return (get_line(buf, len));
}

#include <stdio.h>
#include <fcntl.h>
int	main()
{
	char	*file = "testfile";
	int		fd = open(file, O_RDONLY);
	char	*line;
	int		n = 5;

	if (fd > 2)
	{
		line = get_next_line(fd);
		while (n)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
			n--;
		}
		close(fd);
	}
}
