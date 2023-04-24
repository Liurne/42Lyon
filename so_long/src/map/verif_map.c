/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:59:36 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/24 16:42:24 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verif_map_border(t_data *sl)
{
	int	i;

	i = 0;
	while (i < sl->map.w)
	{
		if (get_tile(sl, i, 0) != '1')
			return (1);
		if (get_tile(sl, i, sl->map.h - 1) != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < sl->map.h)
	{
		if (get_tile(sl, 0, i) != '1')
			return (1);
		if (get_tile(sl, sl->map.w - 1, i) != '1')
			return (1);
		i++;
	}
	return (0);
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
	if (verif_map_border(sl))
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
				init_entity(&(sl->pl), x, y);
				if (sl->pl.pos.x >= sl->win.w / 2)
					sl->map.pos.x = -128 * (((sl->pl.pos.x / 2) / 128) - 1);
				if (sl->pl.pos.y >= sl->win.h / 2)
					sl->map.pos.y = -128 * (((sl->pl.pos.y / 2) / 128));
			}
			if (get_tile(sl, x, y) == 'E')
			{
				sl->map.end.x = x * 128;
				sl->map.end.y = y * 128;
				init_entity(&(sl->cat), x, y);
			}
		}
	}
}
