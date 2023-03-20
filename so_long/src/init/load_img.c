/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/20 17:00:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	new_img(t_data *sl, t_img *img, int w, int h)
{
	img->img = mlx_new_image(sl->win.mlx, w, h);
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		return (1);
	return (0);
}

int	load_img(t_data *sl, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(sl->win.mlx, path, &(img->img_w),
			&(img->img_h));
	if (!img->img)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		return (1);
	return (0);
}

int	load_map_img(t_data *sl)
{
	load_img(sl, "data/texture/grass.xpm", &(sl->tex_map[0]));
	load_img(sl, "data/texture/wall.xpm", &(sl->tex_map[1]));
	load_img(sl, "data/texture/stone.xpm", &(sl->tex_map[2]));
	load_img(sl, "data/texture/stone.xpm", &(sl->tex_map[3]));
	return (0);
}

int	load_pl_img(t_data *sl)
{
	load_img(sl, "data/texture/pl_front.xpm", &(sl->tex_pl[0]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->tex_pl[1]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->tex_pl[2]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->tex_pl[3]));
	return (0);
}
