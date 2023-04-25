/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/25 17:39:03 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# define ERR_ARG "Invalid number of argument"
# define ERR_LIB "Couldn't create a window"
# define ERR_MAP "Map invalid or non-existant"
# define ERR_TEX "Texture invalid or non-existant"

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
	int		w;
	int		h;
	t_vec	pos;
	t_vec	end;
	t_img	img;
	t_img	tex[15];
}	t_map;

typedef struct s_entity
{
	t_vec	pos;
	t_vec	tpos;
	int		w;
	int		h;
	int		dir;
	size_t	nb_mv;
	size_t	d;
	int		inmove;
	int		animation;
	t_img	tex[4][4];
}	t_entity;

typedef struct s_data
{
	t_wins		win;
	t_map		map;
	t_entity	pl;
	t_entity	cat;
	t_img		tex_pl[4][4];
	int			anim;
	int			need_pet;
	int			show_hitbox;
}	t_data;

/* -----window----- */
int		close_window(t_data *sl);
int		init_window(t_data *sl);

/* -----load_img----- */
int		new_img(t_data *sl, t_img *img, int w, int h);
int		load_img(t_data *sl, char *path, t_img *img);
int		destroy_img(t_data *sl, t_img *img);
int		load_map_img(t_data *sl);
int		load_pl_img(t_data *sl);
int		load_dog_img(t_data *sl);
void	destroy_img_map(t_data *sl);
void	destroy_img_pl(t_data *sl);

/* -----display----- */
void	display_entity(t_data *sl, t_entity *e);
void	display_hitbox(t_data *sl, t_entity *e);
int		update_display(t_data *sl);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);

/* -----event----- */
int		event_manager(int keycode, t_data *sl);
void	cat_manager(t_data *sl, int r);
int		entity_collision(t_entity *e1, t_entity *e2);

/* -----map----- */
int		load_file(t_data *sl, char *path);
int		load_map(t_data *sl, char *path);
char	get_tile(t_data *sl, int x, int y);
int		set_tile(t_data *sl, int x, int y, char c);
int		is_still(t_data *sl, char c);
void	init_pl(t_entity *e, int x, int y);
void	init_dog(t_entity *e, int x, int y);
void	init_pos(t_data *sl);
int		verif_map_size(t_data *sl);
int		map_to_img(t_data *sl);
void	reload_tile_img(t_data *sl, int x, int y);

/* -----utils----- */
size_t	ft_strlen(const char *str);

#endif