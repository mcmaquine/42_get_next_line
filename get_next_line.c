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
	return (get_a_line(line, c, len));
}
