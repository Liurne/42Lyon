/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:35 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/28 16:26:07 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_tile(t_data *sl, int x, int y)
{
	if (x < sl->map.w && y < sl->map.h)
		return (sl->map.map[(y * (sl->map.w + 1)) + x]);
	return ('\0');
}

int	put_tile(t_data *sl, int x, int y, char c)
{
	if (x < sl->map.w && y < sl->map.h)
	{
		sl->map.map[(y * (sl->map.w + 1)) + x] = c;
		return (1);
	}
	else
		return (0);
}