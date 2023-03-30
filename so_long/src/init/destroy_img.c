/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:25:14 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/29 17:14:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_img_pl(t_data *sl)
{
	destroy_img(sl, &(sl->tex_pl[0][0]));
	destroy_img(sl, &(sl->tex_pl[0][1]));
	destroy_img(sl, &(sl->tex_pl[0][2]));
	destroy_img(sl, &(sl->tex_pl[0][3]));
	destroy_img(sl, &(sl->tex_pl[1][0]));
	destroy_img(sl, &(sl->tex_pl[1][1]));
	destroy_img(sl, &(sl->tex_pl[1][2]));
	destroy_img(sl, &(sl->tex_pl[1][3]));
	destroy_img(sl, &(sl->tex_pl[2][0]));
	destroy_img(sl, &(sl->tex_pl[2][1]));
	destroy_img(sl, &(sl->tex_pl[2][2]));
	destroy_img(sl, &(sl->tex_pl[2][3]));
	destroy_img(sl, &(sl->tex_pl[3][0]));
	destroy_img(sl, &(sl->tex_pl[3][1]));
	destroy_img(sl, &(sl->tex_pl[3][2]));
	destroy_img(sl, &(sl->tex_pl[3][3]));
}

void	destroy_img_map(t_data *sl)
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