/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:57:30 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/01 14:25:01 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void test_read_from_file()
{
	char	*line;
	int		fdd;
	int		fd = open("testfile", O_RDONLY);
	int		fd2 = open("file2", O_RDONLY);

	fdd = fd;
	if (fdd > 2)
	{
		line = get_next_line(fdd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fdd);
			if (fdd == fd )
				fdd = fd2;
			else
				fdd = fd;
		}
		close(fd2);
		close(fd);
	}
}

void	read_from_input()
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	read_from_input();
}
