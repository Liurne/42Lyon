/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:59:36 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/25 18:01:37 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	recu_finder(t_data *sl, int x, int y, int dir)
{
	if (x >= sl->map.w || x < 0 || y >= sl->map.h || y < 0
		|| get_tile(sl, x, y) == '1')
		return (0);
	if (get_tile(sl, x, y) == 'E')
		set_tile(sl, x, y, 'e');
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

	i = 0;
	while (i < sl->map.w)
	{
		j = 0;
		while (j < sl->map.h)
		{
			if (get_tile(sl, i, j) != 'E' && get_tile(sl, i, j) != 'C'
				&& get_tile(sl, i, j) != 'P' && get_tile(sl, i, j) != '1'
				&& get_tile(sl, i, j) != '0')
				return (0);
			if (i == sl->map.w - 1 || i == 0 || j == sl->map.h - 1 || j == 0)
				if (get_tile(sl, i, j) != '1')
					return (0);
			j++;
		}
		i++;
	}
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
				printf("dim: %d\n", (sl->pl.pos.x - sl->map.w) * 1);
				if (sl->pl.pos.x >= sl->win.w / 2)
					sl->map.pos.x = -128 * (((sl->pl.pos.x / 2) / 128));
				if (sl->pl.pos.y >= sl->win.h / 2)
					sl->map.pos.y = -128 * (((sl->pl.pos.y / 2) / 128));
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
