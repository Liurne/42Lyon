/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/24 17:32:18 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_tile(t_data *sl, int x, int y)
{
	if (x < sl->map.w && y < sl->map.h)
		return (sl->map.map[(y * (sl->map.w + 1)) + x]);
	return ('\0');
}

int	set_tile(t_data *sl, int x, int y, char c)
{
	if (x < sl->map.w && y < sl->map.h)
	{
		sl->map.map[(y * (sl->map.w + 1)) + x] = c;
		return (1);
	}
	else
		return (0);
}

int	load_map(t_data *sl, char *path)
{
	load_file(sl, path);
	if (!verif_map_size(sl))
		return (close_window(sl), 0);
	sl->map.pos.x = 0;
	sl->map.pos.y = 0;
	init_pos(sl);
	return (1);
}
