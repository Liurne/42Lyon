/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:59:36 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/26 16:55:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	recu_finder(t_data *sl, int x, int y, int dir)
{
	printf("nee x: %d, y: %d\n", x, y);
	if (x >= sl->map.w || x < 0 || y >= sl->map.h || y < 0
		|| get_tile(sl, x, y) == '1')
		return (0);
	if (get_tile(sl, x, y) == 'C')
	{
		printf("me\n");
		set_tile(sl, x, y, 'c');
	}
	if (dir != 0)
		recu_finder(sl, x - 1, y, 1);
	if (dir != 1)
		recu_finder(sl, x + 1, y, 0);
	if (dir != 2)
		recu_finder(sl, x, y - 1, 3);
	if (dir != 3)
		recu_finder(sl, x, y + 1, 2);
	return (0);
}

int	verif_map(t_data *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->map.w)
	{
		j = -1;
		while (++j < sl->map.h)
		{
			if (get_tile(sl, i, j) != 'E' && get_tile(sl, i, j) != 'C'
				&& get_tile(sl, i, j) != 'P' && get_tile(sl, i, j) != '1'
				&& get_tile(sl, i, j) != '0')
				return (0);
			if (i == sl->map.w - 1 || i == 0 || j == sl->map.h - 1 || j == 0)
				if (get_tile(sl, i, j) != '1')
					return (0);
		}
	}
	if (is_still(sl, 'E') != 1 || is_still(sl, 'C') < 1 || is_still(sl, 'P')
		!= 1)
		return (0);
	return (1);
}

int	verif_map_size(t_data *sl)
{
	int	tmp;

	tmp = 0;
	while (sl->map.map[tmp] != '\n' && sl->map.map[tmp])
		tmp++;
	if (!sl->map.map[tmp])
		return (0);
	sl->map.w = tmp;
	if ((ft_strlen(sl->map.map) + 1) % (tmp + 1))
		return (0);
	sl->map.h = (ft_strlen(sl->map.map) + 1) / (tmp + 1);
	if (!verif_map(sl))
		return (printf("ok"), 0);
	return (1);
}

void	init_pos(t_data *sl)
{
	int	x;
	int	y;

	x = -1;
	while (++x < sl->map.w)
	{
		y = -1;
		while (++y < sl->map.h)
		{
			if (get_tile(sl, x, y) == 'P')
			{
				init_pl(&(sl->pl), x, y);
				printf("recu\n");
				recu_finder(sl, x, y, 5);
				printf("ok\n");
				init_cam(sl);
			}
			if (get_tile(sl, x, y) == 'E')
			{
				sl->map.end.x = x * 128;
				sl->map.end.y = y * 128;
				init_dog(&(sl->cat), x, y);
			}
		}
	}
}
