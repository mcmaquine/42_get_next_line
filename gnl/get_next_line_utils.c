/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:56:24 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/07 17:35:33 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

char	*join(char *s, char *buf, ssize_t t)
{
	char	*jstr;
	ssize_t	i;
	ssize_t	len_s;

	if (!s && !t)
		return (s);
	i = -1;
	len_s = ft_strlen(s);
	jstr = malloc((len_s + t + 1) * sizeof(char));
	if (!jstr)
		return (NULL);
	while (++i < len_s)
		jstr[i] = s[i];
	if (s)
		free(s);
	while (t)
	{
		jstr[i] = *buf;
		t--;
		buf++;
		i++;
	}
	jstr[i] = '\0';
	return (jstr);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdest;

	if (!dest || !src)
		return (dest);
	tdest = dest;
	tsrc = (unsigned char *)src;
	while (n)
	{
		*tdest = *tsrc;
		tdest++;
		tsrc++;
		n--;
	}
	return (dest);
}
