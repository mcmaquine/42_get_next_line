/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:47:05 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/12 11:32:00 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join(char *btk, char *buf, ssize_t bsize)
{
	size_t	lbtk;
	char	*joined;
	size_t	j;
	size_t	i;
	
	lbtk = ft_strlen(btk);
	joined = (char *)malloc((lbtk + bsize + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	j = 0;
	i = 0;
	if (btk != NULL)
		
	if (bsize > 0)
		ft_cpy(joined, s2, &j);
	joined[j] = '\0';
	return (joined);

}

static char	*update_bucket(char *buf, ssize_t brd, char *btk, ssize_t pos)
{
	size_t	len_bt;
	char	*line;
	char	*new_btk;
	
	line = ft_substr(btk, 0, pos + 1);
	new_btk = ft_substr(btk, pos, ft_strlen(btk));
	free(btk);
	btk = new_btk;
}

/*
Return a string which its last char is '\n' terminatted with '\0'
*/
static char	*get_a_line(int fd, char *bucket)
{
	char		*line;
	char		*buf;
	ssize_t		byte_reads;
	char		*pnl;

	line = NULL;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	pnl = ft_strpchr(bucket, ft_strlen(bucket), 10);
	if(pnl >= 0)
		return ();
	byte_reads = read(fd, buf, BUFFER_SIZE);
	while (byte_reads > 0 || pnl)
	{
		pnl = has_nl(buf, byte_reads);
		if (pnl)
		{
			line = update_bucket(buf, byte_reads, bucket, pnl);
			break ;
		}
		join(line, buf, byte_reads);
		byte_reads = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*bucket;
	char		*line;

	line = get_a_line(fd, bucket);
}
