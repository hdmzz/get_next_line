#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

# define BUFF_SIZE 1

char	*get_next_line(int fd);

char	*read_and_save(int fd, char *save);

char	*check_new_line(char **src, int *trigger);

char	*ft_stash_buff(char const *s1, char const *s2);

char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

int		ft_strchr(const char *s, int c);
char	*ft_get_line(char *save);
char	*ft_save(char *to_save);
char	*ft_strdup(const char *src);



#endif
