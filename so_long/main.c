/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/28 14:14:09 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	close_window(t_wins *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

int	event_manager(int keycode, t_data *data)
{
	printf("keycode:%d\n", keycode);
	if (keycode == 65307)
		close_window(data->win);
	if (keycode == 119 && data->entity->pos.y > 3)
	{
		printf("up\n");
		data->entity->pos.y -= 4;
	}
	if (keycode == 115 && data->entity->pos.y < 495)
	{
		printf("down\n");
		data->entity->pos.y += 4;
	}
	if (keycode == 97 && data->entity->pos.x > 3)
	{
		printf("left\n");
		data->entity->pos.x -= 4;
	}
	if (keycode == 100 && data->entity->pos.x < 495)
	{
		printf("right\n");
		data->entity->pos.x += 4;
	}
	draw_rectanglef(data->renderer, *(data->entity), 0xFFFF0000);
	mlx_put_image_to_window(data->win->mlx, data->win->win,
		data->renderer->img, 0, 0);
	return (keycode);
}

int	main(void)
{
	t_wins		window;
	t_surface	renderer;
	t_rectangle	cube;
	t_data		data;

	cube = (t_rectangle){(t_point){225, 225}, 50, 50};
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 500, 500, "so_long");
	renderer.img = mlx_new_image(window.mlx, 500, 500);
	renderer.addr = mlx_get_data_addr(renderer.img, &renderer.bits_per_pixel,
			&renderer.line_length, &renderer.endian);
	data.win = &window;
	data.entity = &cube;
	data.renderer = &renderer;
	data.map = map_init();

	draw_rectanglef(&renderer, cube, 0x00FF0000);
	draw_rectangle(&renderer, (t_rectangle){
		(t_point){0, 0}, 499, 499}, 0x00FF0000);
	mlx_hook(window.win, 2, 1L << 0, event_manager, &data);
	mlx_hook(window.win, 17, 1L << 0, close_window, &window);
	mlx_put_image_to_window(window.mlx, window.win, renderer.img, 0, 0);
	mlx_loop(window.mlx);
	return (0);
}