#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
	while (*s2 && *s2 != '\n')
		new[j++] = *s2++;
	if (*s2 == '\n')
	{
		new[j] = '\n';
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;

	if (!s)
		return (NULL);
	new_len = ft_strlen(s + start);
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
