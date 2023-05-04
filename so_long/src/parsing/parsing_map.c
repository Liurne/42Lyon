/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:20:55 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/04 16:32:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_file(int fd, char *str)
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

static int	load_file(t_data *sl, char *path)
{
	int	fd;

	if (!ft_strber(path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	sl->map.map = read_file(fd, sl->map.map);
	close(fd);
	return (1);
}

int	load_map(t_data *sl, char *path)
{
	if (!load_file(sl, path))
		return (0);
	if (!verif_map(sl))
		return (0);
	return (1);
}
