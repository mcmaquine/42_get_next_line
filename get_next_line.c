/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/11 15:28:59 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	seek_for_endl(char *buf, size_t len, char *rem)
{
	size_t	i;
	size_t	has_endl;

	i = 0;
	has_endl = 0;
	while (i < len)
	{
		if (buf[i] == 10)
		{
			has_endl = 1;
			break ;
		}
		i++;
	}
	ft_bzero(rem, BUFFER_SIZE);
	if (has_endl)
		ft_memcpy(rem, &buf[i + 1], len - i - 1);
	if (has_endl)
		return (i + 1);
	else
		return (has_endl);
}

/*
If there is any char in remainder copy them to buf, otherwise read from file*/
static ssize_t	get_bytes(int fd, char *buf, char *rmder)
{
	ssize_t	lrem;

	ft_bzero(buf, BUFFER_SIZE);
	lrem = ft_strlen(rmder);
	if (lrem)
		ft_memcpy(buf, rmder, lrem);
	else
		lrem = read(fd, buf, BUFFER_SIZE);
	return (lrem);
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		buf[BUFFER_SIZE];
	static char	remainder[BUFFER_SIZE];
	char		*line;
	ssize_t		end;

	line = NULL;
	if (fd < 0)
		return (NULL);
	read_bytes = get_bytes(fd, buf, remainder);
	while (read_bytes > 0)
	{
		end = seek_for_endl(buf, read_bytes, remainder);
		if (end)
		{
			line = join(line, buf, end);
			break ;
		}
		line = join(line, buf, read_bytes);
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
