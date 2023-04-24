/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/14 16:52:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	new_img(t_data *sl, t_img *img, int w, int h)
{
	img->img = mlx_new_image(sl->win.mlx, w, h);
	if (!img->img)
		close_window(sl);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		close_window(sl);
	return (0);
}

int	load_img(t_data *sl, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(sl->win.mlx, path, &(img->img_w),
			&(img->img_h));
	if (!img->img)
		close_window(sl);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),
			&(img->line_length), &(img->endian));
	if (!img->addr)
		close_window(sl);
	return (0);
}

int	load_map_img(t_data *sl)
{
	load_img(sl, "data/texture/grass.xpm", &(sl->map.tex[0]));
	printf("ok\n");
	load_img(sl, "data/texture/stone.xpm", &(sl->map.tex[1]));
	load_img(sl, "data/texture/border_down.xpm", &(sl->map.tex[2]));
	load_img(sl, "data/texture/border_up.xpm", &(sl->map.tex[3]));
	load_img(sl, "data/texture/border_left.xpm", &(sl->map.tex[4]));
	load_img(sl, "data/texture/border_right.xpm", &(sl->map.tex[5]));
	load_img(sl, "data/texture/border_upright.xpm", &(sl->map.tex[6]));
	load_img(sl, "data/texture/border_downright.xpm", &(sl->map.tex[7]));
	load_img(sl, "data/texture/border_upleft.xpm", &(sl->map.tex[8]));
	load_img(sl, "data/texture/border_downleft.xpm", &(sl->map.tex[9]));
	load_img(sl, "data/texture/collectible.xpm", &(sl->map.tex[10]));
	load_img(sl, "data/texture/col_empty.xpm", &(sl->map.tex[11]));
	load_img(sl, "data/texture/col_inprogress.xpm", &(sl->map.tex[12]));
	load_img(sl, "data/texture/col_full.xpm", &(sl->map.tex[13]));
	load_img(sl, "data/texture/grass_alt.xpm", &(sl->map.tex[14]));
	return (0);
}

int	load_pl_img(t_data *sl)
{
	load_img(sl, "data/texture/pl_front.xpm", &(sl->tex_pl[0][0]));
	load_img(sl, "data/texture/pl_front_walk1.xpm", &(sl->tex_pl[0][1]));
	load_img(sl, "data/texture/pl_front.xpm", &(sl->tex_pl[0][2]));
	load_img(sl, "data/texture/pl_front_walk2.xpm", &(sl->tex_pl[0][3]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->tex_pl[1][0]));
	load_img(sl, "data/texture/pl_back_walk1.xpm", &(sl->tex_pl[1][1]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->tex_pl[1][2]));
	load_img(sl, "data/texture/pl_back_walk2.xpm", &(sl->tex_pl[1][3]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->tex_pl[2][0]));
	load_img(sl, "data/texture/pl_right_walk1.xpm", &(sl->tex_pl[2][1]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->tex_pl[2][2]));
	load_img(sl, "data/texture/pl_right_walk2.xpm", &(sl->tex_pl[2][3]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->tex_pl[3][0]));
	load_img(sl, "data/texture/pl_left_walk1.xpm", &(sl->tex_pl[3][1]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->tex_pl[3][2]));
	load_img(sl, "data/texture/pl_left_walk2.xpm", &(sl->tex_pl[3][3]));
	return (0);
}
