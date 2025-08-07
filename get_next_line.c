/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/07 17:53:49 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	seek_for_endl(char *line, char *rem)
{
	size_t	i;
	size_t	has_endl;
	size_t	len;

	i = 0;
	has_endl = 0;
	len = ft_strlen(line);
	while (line[i])
	{
		if (line[i] == 10)
		{
			has_endl = 1;
			break ;
		}
		i++;
	}
	if (has_endl)
	{
		ft_bzero(rem, ft_strlen(rem));
		ft_memcpy(rem, &line[i + 1], len - i - 1);
	}
	if (has_endl)
		return (i + 1);
	else
		return (has_endl);
}

static char	*from_remainder(char *line, char *remainder)
{
	size_t	lrem;
	size_t	end;
	size_t	i;

	lrem = ft_strlen(remainder);
	if (!line || !lrem)
		return (line);
	i = 0;
	while (remainder[i] && remainder[i] != 10)
		i++;
	if (i >= lrem)
	{
		line = join(line, remainder, lrem);
		ft_bzero(remainder, lrem);
	}
	else
	{
		line = join(line, remainder, i + 1);
		
	}
}

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		buf[BUFFER_SIZE];
	static char	remainder[BUFFER_SIZE];
	char		*line;
	ssize_t		end;

	line = NULL;
	ft_bzero(buf, BUFFER_SIZE);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	if (!read_bytes)
	{
		read_bytes = ft_strlen(remainder);
		ft_memcpy(buf, remainder, ft_strlen(read_bytes));
	}
	while (read_bytes > 0)
	{
		end = seek_for_endl(buf, remainder);
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
