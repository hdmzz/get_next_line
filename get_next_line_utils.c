/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:53:38 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/12/12 10:53:42 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*join;
	int		i;
	int		j;

	i = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (total + 1));
	if (!join || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[total] = 0;
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}
