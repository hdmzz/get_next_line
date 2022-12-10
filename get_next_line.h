#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# define BUFFER_SIZE 10

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*read_and_save(int fd, char *save);
char	*ft_strdup(const char *src);
char	*ft_get_line(char *save);
char	*ft_save(char *to_save);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);

int		ft_strchr(const char *s, int c);

#endif
