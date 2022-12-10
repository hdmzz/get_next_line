#include "get_next_line.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*new;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		new = ft_substr(save, 0, i + 1);
	return (new);
}

char	*ft_save(char *to_save)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("");
	while (to_save[i] && to_save[i] != '\n')
		i++;
	if (to_save[i] == '\n')
	{
		i++;
		temp = ft_strjoin(temp, to_save + i);
		return (temp);
	}
	return (NULL);
}

char	*read_and_save(int fd, char *save)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];

	ret = 1;
	while (!(ft_strchr(save, '\n') && ret != 0))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (!ret)
			return (NULL);
		buff[ret] = 0;
		save = ft_strjoin(save, buff);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (!save)
		save = ft_strdup("");
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
