/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/13 15:58:24 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *bucket, char *buf)
{
	char	*jn;
	
	jn = ft_strjoin(bucket, buf);
	free(jn);
}

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (!nmemb || !size)
		return (NULL);
	pointer = malloc(nmemb * size);
	ft_bzero(pointer, nmemb * size);
	return (pointer);
}

static char	*update_bucket(int fd, char *bucket)
{
	char		*line;
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
		bucket = join(bucket, buf);
		if (ft_strpchr(buf, bytes_read, 10) >= 0)
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
	return (line);
}

/*
Return a string which its last char is '\n' terminatted with '\0'
*/
static char	*get_a_line(int fd, char **bucket)
{
	char	*line;
	char	*new_btk;
	ssize_t	pos;

	pos = ft_strpchr(*btk, ft_strlen(*btk), 10);
	if (pos == -1)
	{
		line = ft_strdup(*b/*
The function returns a pointer to a new string which is a duplicate of the
string s. Memory for the new string is obtained with malloc(3), and can be freed
with free(3). On success, the ft_strdup() function returns a pointer to the
duplicated string. It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*dup;

	slen = ft_strlen(s);
	if (!slen)
		return (NULL);
	dup = (char *)malloc((slen + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup = (char *)ft_memcpy(dup, s, slen);
	dup[slen] = '\0';
	return (dup);
}tk);
		if (line)
		{
			free(*btk);
			*btk = NULL;
		}
	}
	else
	{
		line = ft_substr(*btk, 0, pos + 1);
		new_btk = ft_substr(*btk, pos + 1, ft_strlen(*btk) - (pos + 1));
		free(*btk);
		*btk = new_btk;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;

	if (fd < 0)
		return (NULL);
	bucket = update_bucket(fd, bucket);
	return (line);
}
