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

static char	*update_bucket(char *buf, char *bt, size_t pos)
{
	
}
/*
Return a string which its last char is '\n' terminatted with '\0'
*/
static char	*get_a_line(int fd, char *bucket)
{
	char		*line;
	char		*buf;
	ssize_t		byte_reads;
	size_t		pos_nl;

	line = NULL;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	pos_nl = has_nl(bucket, ft_strlen(bucket));
	if (pos_nl)
		return (update_bucket(buf, bucket, pos_nl));
	byte_reads = read(fd, buf, BUFFER_SIZE);
	while (byte_reads > 0)
	{
		pos_nl = has_nl(buf, byte_reads);
		if (pos_nl)
		{
			line = update_bucket(buf, bucket, pos_nl);
			break ;
		}
		join(line, buf, byte_reads);
		byte_reads = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;

	line = get_a_line(fd, bucket);
}
