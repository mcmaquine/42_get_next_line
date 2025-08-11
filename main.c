/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:32:22 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/11 15:06:30 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test_fd(char *file)
{
	char	*line;
	int		fd;
	int		line_read;

	line_read = 0;
	fd = open(file, O_RDONLY);
 	if (fd > 2)
	{
		line = get_next_line(fd);
		while (line)
		{
			line_read++;
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		printf("\n Total line read: %d\n", line_read);
	}
}

void	test_2_files(char **files)
{
	char	*line;
	int		fdd;
	int		fd2;
	int		fd;

	fd = open(files[1], O_RDONLY);
	fd2 = open(files[2], O_RDONLY);
	fdd = fd;
	if (fdd > 2)
	{
		line = get_next_line(fdd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fdd);
			if (fdd == fd)
				fdd = fd2;
			else
				fdd = fd;
		}
		close(fd2);
		close(fd);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		test_fd(argv[1]);
	else if (argc == 3)
		test_2_files(argv);
	else
		printf("File(s) name(s) missing as parameter\n");
}
