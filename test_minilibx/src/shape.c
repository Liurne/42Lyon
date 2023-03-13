/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:19 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/22 10:50:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_surface *surf, int x, int y, int color)
{
	char	*dst;

	dst = surf->addr + (y * surf->line_length + x * (surf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(t_surface *surf, t_rectangle rect, int color)
{
	size_t	i;

	i = 0;
	while(i < rect.w)
	{
		put_pixel(surf, rect.pos.x + i, rect.pos.y, color);
		put_pixel(surf, rect.pos.x + i, rect.pos.y + rect.h, color);
		i++;
	}
	i = 0;
	while (i < rect.h)
	{
		put_pixel(surf, rect.pos.x, rect.pos.y + i, color);
		put_pixel(surf, rect.pos.x + rect.w, rect.pos.y + i, color);
		i++;
	}
}

void	draw_rectanglef(t_surface *surf, t_rectangle rect, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(i < rect.w)
	{
		j = 0;
		while (j < rect.h)
		{
			put_pixel(surf, rect.pos.x + i, rect.pos.y + j, color);
			j++;
		}
		i++;
	}
	
}