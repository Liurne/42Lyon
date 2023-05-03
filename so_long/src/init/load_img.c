/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:36:17 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/03 17:42:40 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	load_map_img(t_data *sl)
{
	(void)sl;
	load_img(sl, "data/texture/grass.xpm", &(sl->map.tex[0]));
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
	load_img(sl, "data/texture/end_empty.xpm", &(sl->map.tex[11]));
	load_img(sl, "data/texture/end_inprogress.xpm", &(sl->map.tex[12]));
	load_img(sl, "data/texture/end_full.xpm", &(sl->map.tex[13]));
	load_img(sl, "data/texture/grass_alt.xpm", &(sl->map.tex[14]));
	load_img(sl, "data/texture/stone_alt.xpm", &(sl->map.tex[15]));
	load_img(sl, "data/texture/collectible_empty.xpm", &(sl->map.tex[16]));
}

static void	load_pl_img(t_data *sl)
{
	load_img(sl, "data/texture/pl_front.xpm", &(sl->pl.tex[0][0]));
	load_img(sl, "data/texture/pl_front_walk1.xpm", &(sl->pl.tex[0][1]));
	load_img(sl, "data/texture/pl_front.xpm", &(sl->pl.tex[0][2]));
	load_img(sl, "data/texture/pl_front_walk2.xpm", &(sl->pl.tex[0][3]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->pl.tex[1][0]));
	load_img(sl, "data/texture/pl_back_walk1.xpm", &(sl->pl.tex[1][1]));
	load_img(sl, "data/texture/pl_back.xpm", &(sl->pl.tex[1][2]));
	load_img(sl, "data/texture/pl_back_walk2.xpm", &(sl->pl.tex[1][3]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->pl.tex[2][0]));
	load_img(sl, "data/texture/pl_right_walk1.xpm", &(sl->pl.tex[2][1]));
	load_img(sl, "data/texture/pl_right.xpm", &(sl->pl.tex[2][2]));
	load_img(sl, "data/texture/pl_right_walk2.xpm", &(sl->pl.tex[2][3]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->pl.tex[3][0]));
	load_img(sl, "data/texture/pl_left_walk1.xpm", &(sl->pl.tex[3][1]));
	load_img(sl, "data/texture/pl_left.xpm", &(sl->pl.tex[3][2]));
	load_img(sl, "data/texture/pl_left_walk2.xpm", &(sl->pl.tex[3][3]));
	load_img(sl, "data/texture/pl_pet_heart.xpm", &(sl->pl.tex[4][0]));
}

static void	load_dog_img(t_data *sl)
{
	load_img(sl, "data/texture/dog_front.xpm", &(sl->dog.tex[0][0]));
	load_img(sl, "data/texture/dog_front_walk1.xpm", &(sl->dog.tex[0][1]));
	load_img(sl, "data/texture/dog_front.xpm", &(sl->dog.tex[0][2]));
	load_img(sl, "data/texture/dog_front_walk2.xpm", &(sl->dog.tex[0][3]));
	load_img(sl, "data/texture/dog_back.xpm", &(sl->dog.tex[1][0]));
	load_img(sl, "data/texture/dog_back_walk1.xpm", &(sl->dog.tex[1][1]));
	load_img(sl, "data/texture/dog_back.xpm", &(sl->dog.tex[1][2]));
	load_img(sl, "data/texture/dog_back_walk2.xpm", &(sl->dog.tex[1][3]));
	load_img(sl, "data/texture/dog_right.xpm", &(sl->dog.tex[2][0]));
	load_img(sl, "data/texture/dog_right_walk1.xpm", &(sl->dog.tex[2][1]));
	load_img(sl, "data/texture/dog_right.xpm", &(sl->dog.tex[2][2]));
	load_img(sl, "data/texture/dog_right_walk2.xpm", &(sl->dog.tex[2][3]));
	load_img(sl, "data/texture/dog_left.xpm", &(sl->dog.tex[3][0]));
	load_img(sl, "data/texture/dog_left_walk1.xpm", &(sl->dog.tex[3][1]));
	load_img(sl, "data/texture/dog_left.xpm", &(sl->dog.tex[3][2]));
	load_img(sl, "data/texture/dog_left_walk2.xpm", &(sl->dog.tex[3][3]));
	load_img(sl, "data/texture/dog_lay.xpm", &(sl->dog.tex[4][0]));
}

void	load_all_image(t_data *sl)
{
	load_map_img(sl);
	load_pl_img(sl);
	load_dog_img(sl);
}
