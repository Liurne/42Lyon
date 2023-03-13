/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/13 14:55:50 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *sl)
{
	if (!)
	mlx_destroy_window(sl->win.mlx, sl->win.win);
	mlx_destroy_display(sl->win.mlx);
	free(sl->win.mlx);
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
	{
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
		exit(1);
	}
	sl->win.renderer.img = mlx_new_image(sl->win.mlx, 500, 500);
	if (!sl->win.renderer.img)
	{
		mlx_destroy_window(sl->win.mlx, sl->win.win);
		mlx_destroy_display(sl->win.mlx);
		free(sl->win.mlx);
		exit(1);
	}
	return (0);
}
