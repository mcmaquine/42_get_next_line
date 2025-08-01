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
#include "get_next_line.c"

int	main()
{
	int	fd = open(TFILE, O_RDONLY);

	if (fd > 0)
		close(fd);
}
