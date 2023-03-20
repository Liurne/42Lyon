/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:53:20 by jcoquard          #+#    #+#             */
/*   Updated: 2022/12/10 16:48:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	line = ft_strcpy_spe(line, str);
	return (line);
}

char	*ft_left_str(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!new)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_read_line(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		rbytes;

	rbytes = 1;
	while (rbytes && !ft_findchar(str, '\n'))
	{
		rbytes = read(fd, buff, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		buff[rbytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	str = ft_read_line(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	if (!line)
	{
		if (str)
			free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_left_str(str);
	return (line);
}
