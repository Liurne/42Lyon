/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:06:00 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/27 12:39:20 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_error(t_map *map, size_t error)
{
	while (error)
	{
		free(map->map[error]);
		error--;
	}
	free(map->map[error]);
	free(map->map);
	free(map->nbtile_x);
	free(map->nbtile_y);
	free(map->tile_size);
	free(map);
	return (1);
}

void	switch_texture(t_data *data, size_t x, size_t y)
{
	t_rectangle	tile;

	tile = (t_rectangle){x * data->map->tile_size, y * data->map->tile_size,
		data->map->tile_size, x * data->map->tile_size};
	if (data->map->map[x][y] == 0)
		draw_rectanglef(data->renderer, &tile, 0xFF000000);
	else if (data->map->map[x][y] == 1)
		draw_rectanglef(data->renderer, &tile, 0xFF000000);
	else if (data->map->map[x][y] == 2)
		draw_rectanglef(data->renderer, &tile, 0xFF000000);
	else
		draw_rectanglef(data->renderer, &tile, 0xFF000000);
}

void	draw_map(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map->nbtile_x)
	{
		while (j < data->map->nbtile_y)
		{
			switch_texture(data, i, j);
			j++;
		}
		i++;
	}
}

t_map	*map_init(void)
{
	t_map	*res;
	size_t	i;

	res = (t_map *)malloc(sizeof(t_map));
	if (!res)
	{
		printf("error struct\n");
		return (NULL);
	}
	res->nbtile_x = 10;
	res->nbtile_y = 10;
	res->tile_size = 50;
	res->map = (int **)malloc(sizeof(int *) * res->nbtile_x);
	if (!res->map)
	{
		printf("error map\n");
		return (NULL);
	}
	i = 0;
	while (i < res->nbtile_y)
	{
		res->map[i] = (int *)malloc(sizeof(int) * res->nbtile_y);
		if (!res->map[i])
		{
			map_error(res, i);
			printf("error map");
			return (NULL);
		}
		i++;
	}
	return (res);
}
