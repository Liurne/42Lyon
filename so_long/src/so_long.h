/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/20 17:07:05 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_wins
{
	void	*mlx;
	void	*win;
	t_img	renderer;
	int		w;
	int		h;
}	t_wins;

typedef struct s_map
{
	char	*map;
	int		width;
	int		height;
	t_vec	pos;
	t_img	img;
}	t_map;

typedef struct s_entity
{
	t_vec	pos;
	int		dir;
	size_t	nb_mv;
}	t_entity;

typedef struct s_data
{
	t_wins		win;
	t_map		map;
	t_entity	pl;
	t_img		tex_map[4];
	t_img		tex_pl[4];
}	t_data;

/* -----window----- */
int		close_window(t_data *sl);
int		init_window(t_data *sl);

/* -----load_img----- */
int		new_img(t_data *sl, t_img *img, int w, int h);
int		load_img(t_data *sl, char *path, t_img *img);
int		load_map_img(t_data *sl);
int		load_pl_img(t_data *sl);

/* -----display----- */
int		update_display(t_data *sl);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);

/* -----event----- */
int		event_manager(int keycode, t_data *sl);

/* -----map----- */
char	get_tile(t_data *sl, int x, int y);
int		map_to_img(t_data *sl);

#endif