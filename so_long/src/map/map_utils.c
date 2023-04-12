/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:35 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/12 14:38:48 by jcoquard         ###   ########.fr       */
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

	i = 0;
	while (sl->map.map[i])
	{
		if (sl->map.map[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	init_entity(t_entity *e, int x, int y)
{
	e->pos.x = x * 64;
	e->pos.y = y * 64;
	e->dir = 0;
	e->nb_mv = 0;
	e->d = 0;
	e->inmove = 0;
}
