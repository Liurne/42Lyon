/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:39:38 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/04 11:52:09 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_read(int fd, char *str)
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
	sl->map.map = malloc(sizeof(char));
	if (!sl->map.map)
		return (close(fd), 0);
	sl->map.map = '\0';
	sl->map.map = ft_read(fd, sl->map.map);
	close(fd);
	return (1);
}
