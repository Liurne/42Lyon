/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:35 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/26 16:09:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	is_still(t_data *sl, char c)
{
	int	i;
	int tmp;

	i = 0;
	tmp = 0;
	while (sl->map.map[i])
	{
		if (sl->map.map[i] == c)
			tmp++;
		i++;
	}
	return (tmp);
}

void	init_cam(t_data *sl)
{
	if (sl->pl.pos.x >= sl->win.w / 2)
		sl->map.pos.x = -128 * (((sl->pl.pos.x / 2) / 128));
	if (((sl->map.w * 128) - sl->pl.pos.x) < sl->win.w / 2)
		sl->map.pos.x = (sl->map.w * -128) + sl->win.w;
	if (sl->pl.pos.y >= sl->win.h / 2)
		sl->map.pos.y = -128 * (((sl->pl.pos.y / 2) / 128));
	if (((sl->map.h * 128) - sl->pl.pos.y) < sl->win.h / 2)
		sl->map.pos.y = (sl->map.h * -128) + sl->win.h;
}

void	init_pl(t_entity *e, int x, int y)
{
	e->pos.x = x * 128;
	e->pos.y = y * 128;
	e->tpos.x = 40;
	e->tpos.y = 32;
	e->w = 48;
	e->h = 92;
	e->dir = 0;
	e->nb_mv = 0;
	e->d = 0;
	e->inmove = 0;
	e->animation = 0;
}

void	init_dog(t_entity *e, int x, int y)
{
	e->pos.x = x * 128;
	e->pos.y = y * 128;
	e->tpos.x = 32;
	e->tpos.y = 32;
	e->w = 64;
	e->h = 92;
	e->dir = 0;
	e->nb_mv = 0;
	e->d = 0;
	e->inmove = 0;
	e->animation = 0;
}
