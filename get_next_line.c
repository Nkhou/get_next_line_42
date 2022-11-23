/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:59:46 by nkhoudro          #+#    #+#             */
/*   Updated: 2022/11/22 22:35:41 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strdup( char *s1)
{
	char	*c;
	int		i;

	i = 0;
	c = malloc(sizeof(char ) * (ft_strlen((char *)s1) + 1));
	if (c == NULL)
		return (NULL);
	while (s1[i])
	{
		c[i] = (char )s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static char	*ft_read_line(int fd, char *str)
{
	char	*buff;
	int		nb;

	if (!str)
		str = ft_strdup("");
	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(str), NULL);
	nb = 1;
	while (nb > 0 && !ft_strchr(str, '\n'))
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
			return (free(buff), free(str), NULL);
		if (!str)
			return (free(buff), free(str), NULL);
		buff[nb] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (free(buff), str);
}

static char	*ft_get_to_back(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i] && (str[i] != '\n'))
		i++;
	if (str[i] == '\n')
		line = (char *) malloc(sizeof(char) * (i + 2));
	else
		line = (char *) malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!line)
		return (NULL);
	while ((str[i] != '\n') && str[i])
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	return (line[i] = '\0', line);
}

static char	*ft_get_rest(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line || !*line)
		return (free(line), NULL);
	while (line[i] != '\n' && line[i])
		i++;
	str = (char *) malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!str)
		return (free(line), free(str), NULL);
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (free(line), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(str), str = NULL);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_to_back(str);
	str = ft_get_rest(str);
	return (line);
}
