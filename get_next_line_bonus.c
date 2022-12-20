/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:53:53 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/12/20 15:53:55 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_save(char *save)
{
	char	*new_save;
	char	*ptr;
	int		len;

	ptr = ft_strchr(save, '\n');
	if (!ptr)
	{
		new_save = NULL;
		return (ft_free(&save));
	}
	else
		len = (ptr - save) + 1;
	if (!save[len])
		return (ft_free(&save));
	new_save = ft_substr(save, len, ft_strlen(save) - len);
	ft_free(&save);
	if (!new_save)
		return (NULL);
	return (new_save);
}

char	*new_line(char *save)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(save, '\n');
	len = (ptr - save) + 1;
	line = ft_substr(save, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_and_save(int fd, char *save)
{
	int		ret;
	char	*buffer;

	ret = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&save));
	buffer[0] = '\0';
	while (ret > 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			buffer[ret] = '\0';
			save = ft_strjoin(save, buffer);
		}
	}
	free(buffer);
	if (ret == -1)
		return (ft_free(&save));
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((save[fd] && !ft_strchr(save[fd], '\n')) || !save[fd])
		save[fd] = read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = new_line(save[fd]);
	if (!line)
		return (ft_free(&save[fd]));
	save[fd] = clean_save(save[fd]);
	return (line);
}
