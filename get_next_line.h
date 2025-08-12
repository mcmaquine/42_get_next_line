/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:04:02 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/12 10:50:57 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define MAX_FD	1048576

char	*ft_strchr(const char *s, size_t len, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
#endif
