/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 14:15:18 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_wins *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

int	event_manager(int keycode, t_wins *win)
{
	printf("keycode:%d\n", keycode);
	if (keycode == 65307)
		close_window(win);
	return (keycode);
}

int	main(void)
{
	t_wins	window;
	t_img	img;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(window.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	put_pixel(&img, 5, 5, 0x00FF0000);
	mlx_hook(window.win, 2, 1L << 0, event_manager, &window);
	mlx_hook(window.win, 17, 1L << 0, close_window, &window);
	mlx_put_image_to_window(window.mlx, window.win, img.img, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}