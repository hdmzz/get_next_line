#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	ret;
	char buff[BUFF_SIZE + 1];

	while (ret = read(fd, buff, BUFF_SIZE))
	{
		write(1, buff, ft_strlen(buff));
		
	}
}
