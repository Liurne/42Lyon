/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/04 14:59:35 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *sl)
{
	printf("ok\n");
	destroy_img_map(sl);
	printf("ok\n");
	destroy_img_pl(sl);
	printf("ok\n");
	destroy_img(sl, &(sl->map.img));
	destroy_img(sl, &(sl->win.renderer));
	if (sl->map.map)
		free(sl->map.map);
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
	sl->win.w = 640;
	sl->win.h = 384;
	sl->win.mlx = mlx_init();
	if (!sl->win.mlx)
		exit(1);
	sl->win.win = mlx_new_window(sl->win.mlx, sl->win.w, sl->win.h, "so_long");
	if (!sl->win.win)
		close_window(sl);
	new_img(sl, &(sl->win.renderer), sl->win.w, sl->win.h);
	if (!sl->win.renderer.img)
		close_window(sl);
	sl->anim = 0;
	return (0);
}
