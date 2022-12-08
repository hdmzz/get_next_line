#include "get_next_line.h"

char	*read_and_save(int fd, char *str)
{
	int			ret;
	int			i;
	char		*buff;
	char		*line;
	static char	*temp;

	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	line = "";
	if (temp)
		line = ft_strjoin(line, temp);
	temp = malloc (sizeof(char) * BUFF_SIZE + 1);
	if (!buff || !temp)
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		i = 0;
		if (ret == -1)
			return (NULL);
		while (buff[i] && buff[i] != '\n')
			i++;
		line = ft_strjoin(line, buff);
		if (buff[i] == '\n')
		{
			i++;
			temp = ft_strjoin(temp, buff + i);
			break;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = read_and_save(fd, str);
	if (!str)
		return (NULL);
	return (str);
}

/*char 	*buff;
	static char	*save;
	char	*next;
	static int	nl_start;
	int ret;
	static int	i;
	int	nl_lenght;
	int found_sep = 0;

	nl_start = 0;
	ret = 0;
	buff = malloc(sizeof(char) * BUFF_SIZE);
	while (!found_sep && (ret = read(fd, buff, BUFF_SIZE)))//les n bytes lus sont stockés dans buff
	{
		next = ft_strchr(buff, '\n');

		if (!next)
			save = ft_strjoin(save, buff);
		else
			found_sep = 1;
		nl_lenght = buff - next;
	}
	printf("%s\n", save);*/
