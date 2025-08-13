/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:57:30 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/13 10:29:22 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	two_files(char **files)
{
	char	*line;
	int		fdd;
	int		fd;
	int		fd2;

	fd = open(files[1], O_RDONLY);
	fd2 = open(files[2], O_RDONLY);
	fdd = fd;
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

void	one_file(char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		one_file(argv[1]);
	else if (argc == 3)
		two_files(argv);
	else
		printf("Must have one or two parameters\n");
	return (EXIT_SUCCESS);
}
