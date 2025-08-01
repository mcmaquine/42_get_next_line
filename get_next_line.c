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

static size_t count_char(char *buf)
{
	size_t cnt;

	while(*buf && *buf != '\n')
	{
		cnt++;
		buf++;
	}
}

static	void	buff_clear(char *buf)
{
	while (*buf)
	{
		*buf = '\0';
		buf++;
	}
}

static	char	*get_line(char *buf, size_t s)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * s);
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
	static char	buf[BUFFER_SIZE];
	size_t		line_len;

	read_bytes = read(fd, buf, BUFFER_SIZE);
	line_len = count_char(*buf);
	return (get_line(buf, line_len));
}
