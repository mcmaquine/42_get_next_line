/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:51:53 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/15 12:58:57 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

/*
The function returns a pointer to the first occurence of the character c in the
string s.
Return a pointer to the matched character or NULL if the character is not found
*/
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	else
		return (NULL);
}

/*
Allocates memory (using malloc(3)) and returns a substring from the string 's'
The substring starts at index 'start' and has a maximum length of 'len'.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	charleft;
	size_t	st;
	char	*sub;

	if (!s || !len)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(sizeof(char)));
	charleft = ft_strlen(&s[start]);
	if (charleft > len)
		charleft = len;
	sub = malloc((charleft + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	st = 0;
	while (s[start] && (st < len))
	{
		sub[st] = s[start];
		st++;
		start++;
	}
	sub[st] = '\0';
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	char	*str1;
	char	*str2;
	char	*start;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	start = joined;
	while (*str1)
		*joined++ = *str1++;
	while (*str2)
		*joined++ = *str2++;
	*joined = '\0';
	return (start);
}

/*
Allocates memory with malloc and initialize with zeroes
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	total_bytes;
	size_t	i;

	total_bytes = nmemb * size;
	if (!nmemb || !size || size != total_bytes / nmemb)
		return (NULL);
	pointer = malloc(total_bytes);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < total_bytes)
	{
		((unsigned char *)pointer)[i] = '\0';
		i++;
	}
	return (pointer);
}
