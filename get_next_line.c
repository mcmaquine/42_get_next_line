/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/12 18:01:52 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char **btk, char *buf, ssize_t bsize)
{
	size_t	lbtk;
	char	*joined;

	lbtk = ft_strlen(*btk);
	joined = (char *)malloc((lbtk + bsize + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	if (btk)
		ft_memcpy(joined, *btk, lbtk);
	if (bsize > 0)
		ft_memcpy(&joined[lbtk], buf, bsize);
	joined[lbtk + bsize] = '\0';
	free(*btk);
	*btk = NULL;
	return (joined);
}

static char	*update_bucket(char *buf, ssize_t byte_read, char **btk)
{
	char	*line;
	char	*new_btk;
	ssize_t	pos;

	new_btk = join(btk, buf, byte_read);
	pos = ft_strpchr(new_btk, ft_strlen(new_btk), 10);
	if (pos == -1)
	{
		line = ft_strdup(new_btk);
		if (!ft_strlen(line))
			line = NULL;
		free(new_btk);
	}
	else
	{
		line = ft_substr(new_btk, 0, pos + 1);
		*btk = ft_substr(new_btk, pos + 1, ft_strlen(new_btk) - pos);
	}
	if (!ft_strlen(*btk) && *btk)
		free(btk);
	return (line);
}

/*
Return a string which its last char is '\n' terminatted with '\0'
*/
static char	*get_a_line(int fd, char **bucket)
{
	char		*line;
	char		*buf;
	ssize_t		byte_reads;

	line = NULL;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	byte_reads = read(fd, buf, BUFFER_SIZE);
	while (byte_reads > 0)
	{
		if (ft_strpchr(buf, byte_reads, 10) >= 0)
		{
			line = update_bucket(buf, byte_reads, bucket);
			break ;
		}
		*bucket = join(bucket, buf, byte_reads);
		byte_reads = read(fd, buf, BUFFER_SIZE);
	}
	line = update_bucket(NULL, 0, bucket);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;
	ssize_t		pnl;

	if (fd < 0)
		return (NULL);
	pnl = ft_strpchr(bucket, ft_strlen(bucket), 10);
	if (pnl >= 0)
		return (update_bucket(NULL, 0, &bucket));
	line = get_a_line(fd, &bucket);
	return (line);
}
