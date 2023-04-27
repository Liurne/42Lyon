/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:43:59 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 16:13:40 by jcoquard         ###   ########.fr       */
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

int	is_still(char *map, char c)
{
	int	tmp;

	tmp = 0;
	while (*map)
	{
		if (*map == c)
			tmp++;
		map++;
	}
	return (tmp);
}