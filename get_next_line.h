/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:45:27 by nkhoudro          #+#    #+#             */
/*   Updated: 2022/11/22 04:23:07 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_read_line(int fd, char *str);
char	*ft_get_to_back(char *str);
char	*ft_get_rest(char *line);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
#endif