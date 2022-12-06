#include "get_next_line.h"

char	*stash_buff(char *src)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (i && src[i] != '\n')
	{
		tmp[i] = src[i];
		i++;
	}
}

char	*read_and_save(int fd, char *save)
{
	int			ret;
	int			new_line_found;
	int			i;
	char		*buff;
	static char	*next;

	new_line_found = 0;
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buff)
		return (NULL);
	if (next)
		save = ft_strjoin(save, next);
	while (ret = read(fd, buff, BUFF_SIZE) && new_line_found == 0)
	{
		i = 0;
		while (buff[i++])
			if (buff[i] == '\n')
			{
				next = ft_strjoin(next, buff + i);
				buff[i] = '\0';
				new_line_found = 1;
			}
		save = ft_strjoin(save, buff);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char	*buff;

	buff = read_and_save(fd, buff);
	if (!buff)
		return (NULL);
	return (buff);
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
