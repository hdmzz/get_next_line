/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:53:17 by hdamitzi          #+#    #+#             */
/*   Updated: 2022/12/12 10:53:19 by hdamitzi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);


#endif
