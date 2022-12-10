#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	char	*buff;
	int		slen;

	slen = ft_strlen(s1);
	newstr = (char *)malloc(sizeof(char) * (slen + 1));
	if (!newstr)
		return (NULL);
	buff = (char *)s1;
	newstr[slen] = 0;
	while (slen--)
		newstr[slen] = buff[slen];
	return (newstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		j;

	new = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 2));
	if (!new)
		return (NULL);
	j = 0;
	while (*s1)
		new[j++] = *s1++;
	while (*s2)
		new[j++] = *s2++;
	new[j] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;

	new_len = 0;
	while (s[new_len] && s[new_len] != '\n')
		new_len++;
	if (s[new_len] == '\n')
		new_len += 1;
	if (!s)
		return (NULL);
	if (!(new_len < len))
		new_len = len;
	new = (char *)malloc(sizeof(char) * (new_len + 1));
	if (!new)
		return (NULL);
	new[new_len] = '\0';
	while (new_len--)
		new[new_len] = s[start + new_len];
	return (new);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (1);
	return (0);
}
