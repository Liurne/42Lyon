/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:39:38 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/12 15:07:35 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_strber(const char *haystack)
{
	size_t	i;
	size_t	j;
	char	*ber;

	ber = ".ber\0";
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == ber[j] && ber[j] && haystack[i + j])
			j++;
		if (!ber[j] && !haystack[i + j])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (res);
}

static char	*ft_read(int fd, char *str)
{
	char	buff[43];
	int		rbytes;

	rbytes = 1;
	while (rbytes)
	{
		rbytes = read(fd, buff, 42);
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

int	load_file(t_data *sl, char *path)
{
	int	fd;

	if (!ft_strber(path))
		return (printf("file\n"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (printf("fd\n"), 0);
	sl->map.map = ft_read(fd, sl->map.map);
	close(fd);
	return (1);
}
