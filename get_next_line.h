/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaquine <mmaquine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:04:02 by mmaquine          #+#    #+#             */
/*   Updated: 2025/08/06 13:51:14 by mmaquine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
ssize_t	look_for_endl(char **line, char *buf, ssize_t s, char *rem);
char	*join(char *s, char *buf, ssize_t t);
void	*ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
#endif
