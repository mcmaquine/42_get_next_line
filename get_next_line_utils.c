/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:56:24 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/04 20:57:05 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*tsrc;

	cdest = (unsigned char *)dest;
	tsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}

void	ft_bzero(void *buf, size_t n)
{
	unsigned char	*dest;

	dest = buf;
	while (n)
	{
		*dest = '\0';
		dest++;
		n--;
	}
}

/*
Return a string which its last char is '\n' terminatted with '\0'
*/
char	*get_line(char *buf, size_t s)
{
	char	*line;

	s++;
	line = (char *)malloc(sizeof(char) * (s + 1));
	line[s] = '\0';
	while (--s)
	{
		line[s] = buf[s];
	}
	*line = *buf;
	return (line);
}

char	*join(char *s, char *buf, size_t t)
{
	char	*jstr;
	char	*str1;
	size_t	i;

	i = 0;
	str1 = get_line(buf, t);
	jstr = malloc((ft_strlen(s) + t + 1) * sizeof(char));
	if (s)
	{
		jstr = ft_memcpy(jstr, s, ft_strlen(s));
		i = ft_strlen(s);
		free(s);
	}
	if (t)
		jstr = ft_memcpy(&jstr[i], str1, t);
	jstr[i] = '\0';
	return (jstr);
}
