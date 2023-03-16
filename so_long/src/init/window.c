/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/16 14:36:04 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *sl)
{
	if (sl->win.win)
		mlx_destroy_window(sl->win.mlx, sl->win.win);
	if (sl->win.mlx)
	{
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
	}
	exit(0);
	return (0);
}

int	init_window(t_data *sl)
{
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		exit(1);
	sl->win.win = mlx_new_window(sl->win.mlx, 500, 500, "so_long");
	if (!sl->win.win)
		close_window(sl);
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, 500, 500);
	if (!sl->win.renderer.img)
		close_window(sl);
	return (0);
}
