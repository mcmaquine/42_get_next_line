/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/15 15:47:27 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *bucket, char *buf)
{
	char	*jn;

	jn = ft_strjoin(bucket, buf);
	free(bucket);
	return (jn);
}

char	*update_bucket(char *bucket)
{
	char	*n_pos;
	size_t	size;
	char	*new_bucket;

	if (!bucket)
		return (NULL);
	if (!bucket[0])
	{
		free(bucket);
		return (NULL);
	}
	n_pos = ft_strchr(bucket, '\n');
	if (n_pos)
	{
		size = ft_strlen(bucket) - (n_pos - bucket + 1);
		new_bucket = ft_substr(n_pos, 1, size);
		free(bucket);
		return (new_bucket);
	}
	free(bucket);
	return (NULL);
}

char	*read_to_bucket(int fd, char *bucket)
{
	char		*buf;
	ssize_t		bytes_read;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	if (!bucket)
		bucket = (char *)ft_calloc(1, sizeof(char));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		bucket = join(bucket, buf);
		if (ft_strchr(bucket, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(buf);
		free(bucket);
		return (NULL);
	}
	free(buf);
	return (bucket);
}

/*
Return a string which its last char is '\n' terminatted with '\0'
*/
char	*get_a_line(char *bucket)
{
	char	*line;
	char	*n_pos;
	size_t	size;

	n_pos = ft_strchr(bucket, '\n');
	if (n_pos)
		size = n_pos - bucket + 1;
	else
		size = ft_strlen(bucket);
	line = ft_substr(bucket, 0, size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bucket = read_to_bucket(fd, bucket);
	if (!bucket)
		return (NULL);
	line = get_a_line(bucket);
	bucket = update_bucket(bucket);
	return (line);
}
