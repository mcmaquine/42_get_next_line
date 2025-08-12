/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:51:53 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/12 11:38:24 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (!s && s[len])
		len++;
	return (len);
}

/*
The function returns the psoiton to the first occurence of the character c in 
the string s.
Return the position to the matched character or -1 if the character is not found
*/
ssize_t	ft_strpchr(const char *s, size_t len, char c)
{
	int	i;

	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
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

	if (!s)
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

/*
The function copies n bytes from memory area src to memory area dest. The memory
area must not overlap.
*/
void	*ft_memcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (dest);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
