/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhoudro <nkhoudro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:59:17 by nkhoudro          #+#    #+#             */
/*   Updated: 2022/11/22 04:21:45 by nkhoudro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

static char	*ft_strcon(size_t d, char const *s1, char const *s2, size_t mys1)
{
	char		*p;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	p = (char *)malloc(sizeof(char) * (d + 1));
	if (!p)
		return (NULL);
	ft_bzero(p, d + 1);
	while (i < d)
	{
		if (i < mys1)
			p[i] = s1[i];
		else
			p[i] = s2[j++];
		i++;
	}
	p[i] = '\0';
	return (free((char *)s1), p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		d;
	int			mys2;
	int			mys1;
	char		*p;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	mys1 = ft_strlen(s1);
	mys2 = ft_strlen(s2);
	d = mys1 + mys2 + 1;
	p = ft_strcon(d, s1, s2, mys1);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	if (!p)
		return (NULL);
	while (p[i])
	{
		if (p[i] == (char)c)
		{
			return (p + i);
		}
		i++;
	}
	if (p[i] == '\0' && (char)c == '\0')
		return (&p[i]);
	return (NULL);
}
