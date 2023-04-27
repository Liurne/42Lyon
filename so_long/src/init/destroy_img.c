/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:14 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 17:26:53 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	destroy_img_pl(t_data *sl)
{
	destroy_img(sl, &(sl->pl.tex[0][0]));
	destroy_img(sl, &(sl->pl.tex[0][1]));
	destroy_img(sl, &(sl->pl.tex[0][2]));
	destroy_img(sl, &(sl->pl.tex[0][3]));
	destroy_img(sl, &(sl->pl.tex[1][0]));
	destroy_img(sl, &(sl->pl.tex[1][1]));
	destroy_img(sl, &(sl->pl.tex[1][2]));
	destroy_img(sl, &(sl->pl.tex[1][3]));
	destroy_img(sl, &(sl->pl.tex[2][0]));
	destroy_img(sl, &(sl->pl.tex[2][1]));
	destroy_img(sl, &(sl->pl.tex[2][2]));
	destroy_img(sl, &(sl->pl.tex[2][3]));
	destroy_img(sl, &(sl->pl.tex[3][0]));
	destroy_img(sl, &(sl->pl.tex[3][1]));
	destroy_img(sl, &(sl->pl.tex[3][2]));
	destroy_img(sl, &(sl->pl.tex[3][3]));
}

static void	destroy_img_dog(t_data *sl)
{
	destroy_img(sl, &(sl->dog.tex[0][0]));
	destroy_img(sl, &(sl->dog.tex[0][1]));
	destroy_img(sl, &(sl->dog.tex[0][2]));
	destroy_img(sl, &(sl->dog.tex[0][3]));
	destroy_img(sl, &(sl->dog.tex[1][0]));
	destroy_img(sl, &(sl->dog.tex[1][1]));
	destroy_img(sl, &(sl->dog.tex[1][2]));
	destroy_img(sl, &(sl->dog.tex[1][3]));
	destroy_img(sl, &(sl->dog.tex[2][0]));
	destroy_img(sl, &(sl->dog.tex[2][1]));
	destroy_img(sl, &(sl->dog.tex[2][2]));
	destroy_img(sl, &(sl->dog.tex[2][3]));
	destroy_img(sl, &(sl->dog.tex[3][0]));
	destroy_img(sl, &(sl->dog.tex[3][1]));
	destroy_img(sl, &(sl->dog.tex[3][2]));
	destroy_img(sl, &(sl->dog.tex[3][3]));
}

static void	destroy_img_map(t_data *sl)
{
	destroy_img(sl, &(sl->map.tex[0]));
	destroy_img(sl, &(sl->map.tex[1]));
	destroy_img(sl, &(sl->map.tex[2]));
	destroy_img(sl, &(sl->map.tex[3]));
	destroy_img(sl, &(sl->map.tex[4]));
	destroy_img(sl, &(sl->map.tex[5]));
	destroy_img(sl, &(sl->map.tex[6]));
	destroy_img(sl, &(sl->map.tex[7]));
	destroy_img(sl, &(sl->map.tex[8]));
	destroy_img(sl, &(sl->map.tex[9]));
	destroy_img(sl, &(sl->map.tex[10]));
	destroy_img(sl, &(sl->map.tex[11]));
	destroy_img(sl, &(sl->map.tex[12]));
	destroy_img(sl, &(sl->map.tex[13]));
	destroy_img(sl, &(sl->map.tex[14]));
}

void	destroy_all_image(t_data *sl)
{
	destroy_img_map(sl);
	destroy_img_pl(sl);
	destroy_img_dog(sl);
}
