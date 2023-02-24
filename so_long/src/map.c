/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:06:00 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/22 11:29:21 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_error(t_map *map, size_t error)
{
	while(error)
	{
		free(map->map[error]);
		error--;
	}
	free(map->map[error]);
	free(map->map);
	free(map->nbtileX);
	free(map->nbtileY);
	free(map->tile_size);
	free(map);
	return (1);
}

int draw_map
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
	res->nbtileX = 10;
	res->nbtileY = 10;
	res->tile_size = 50;
	res->map = (int**)malloc(sizeof(int*) * res->nbtileX);
	if (!res->map)
	{
		printf("error map\n");
		return (NULL);
	}
	i = 0;
	while (i < res->nbtileY)
	{
		res->map[i] = (int*)malloc(sizeof(int) * res->nbtileY);
		if(!res->map[i])
		{
			map_error(res, i);
			printf("error map*");
			return (NULL);
		}
		i++;
	}
	return (res);
}
