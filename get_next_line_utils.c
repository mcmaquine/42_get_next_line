/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:56:24 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/06 14:57:24 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && *s)
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

ssize_t	look_for_endl(char **line, char *buf, ssize_t s, char *rem)
{
	ssize_t	i;
	ssize_t	has_endl;
	
	i = -1;
	has_endl = 0;
	while (++i < s)
	{
		if (buf[i] == 10)
		{
			has_endl = 1;
			break ;
		}
	}
	if (has_endl)
	{
		*line = join(*line, buf, s);
		ft_bzero(rem, s);
		ft_memcpy(rem, &buf[i + 1], s - i - 1);
	}
	else
	{
		*line = join(*line, buf, s);
		ft_bzero(rem, s);
	}
	return (has_endl);
}

char	*join(char *s, char *buf, ssize_t t)
{
	char	*jstr;
	char	*joined;
	size_t	i;

	i = 0;
	if (!s && !t)
		return (NULL);
	jstr = malloc((ft_strlen(s) + t + 1) * sizeof(char));
	if (!jstr)
		return (NULL);
	joined = jstr;
	if (s)
	{
		jstr = ft_memcpy(jstr, s, ft_strlen(s));
		i = ft_strlen(s);
		free(s);
	}
	if (t)
		jstr = ft_memcpy(&jstr[i], buf, t);
	jstr[i + t] = '\0';
	return (joined);
}

void	*ft_bzero(void *s, size_t n)
{ 
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = '\0';
		n--;
		dest++;
	}
	return (s);
}

