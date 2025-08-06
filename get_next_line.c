/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/06 14:12:35 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		read_bytes;
	char		buf[BUFFER_SIZE];
	static char	remainder[BUFFER_SIZE];
	char		*line;
	ssize_t		end;

	line = NULL;
	end = 0;
	read_bytes = read(fd, buf, BUFFER_SIZE);
	line = join(line, remainder, ft_strlen(remainder));
	while (read_bytes > 0)
	{
		end = look_for_endl(&line, buf, read_bytes, remainder);
		if (end)
			break ;
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (!line && !read_bytes)
		return (NULL);
	return (line);
}
