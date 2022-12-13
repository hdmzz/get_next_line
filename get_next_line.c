/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:53:06 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/12/12 10:53:08 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_join_and_free(char *str_stic, char *to_save)
{
	char	*new;

	new = ft_strjoin(str_stic, to_save);
	free(str_stic);
	return (new);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*new;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (save[i] && save[i] == '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		save[i++] = '\n';
	return (new);
}

char	*ft_save(char *to_save)
{
	int		i;
	char	*temp;

	i = 0;
	while (to_save[i] && to_save[i] != '\n')
		i++;
	if (!to_save[i])
	{
		free(to_save);
		return (NULL);
	}
	temp = malloc(sizeof(char) * (ft_strlen(to_save) - i) + 1);
	if (!temp)
		return (NULL);
	i++;
	while (to_save[i])
		*temp++ = to_save[i++];
	free(to_save);
	return (temp);
	/* if (to_save[i] == '\n')
	{
		i++;
		temp = ft_strjoin(temp, to_save + i);
		free(to_save);
		return (temp);
	}
	return (NULL); */
}

char	*read_and_save(int fd, char *save)
{
	int		ret;
	char	*buff;

	if (!save)
		save = ft_strdup("");
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[ret] = 0;
		save = ft_join_and_free(save, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
