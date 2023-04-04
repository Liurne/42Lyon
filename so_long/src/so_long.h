/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/04 16:19:35 by jcoquard         ###   ########.fr       */
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
	int		dir;
	size_t	nb_mv;
	size_t	d;
	int		inmove;
}	t_entity;

typedef struct s_data
{
	t_wins		win;
	t_map		map;
	t_entity	pl;
	t_img		tex_pl[4][4];
	int			anim;
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
void	destroy_img_map(t_data *sl);
void	destroy_img_pl(t_data *sl);

/* -----display----- */
int		update_display(t_data *sl);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);

/* -----event----- */
int		event_manager(int keycode, t_data *sl);

/* -----map----- */
int		load_map(t_data *sl, char *path);
char	get_tile(t_data *sl, int x, int y);
int		put_tile(t_data *sl, int x, int y, char c);
int		is_still(t_data *sl, char c);
int		map_to_img(t_data *sl);
void	reload_tile_img(t_data *sl, int x, int y);

/* -----utils----- */
size_t	ft_strlen(const char *str);
int		ft_strber(const char *haystack);
char	*ft_strjoin(char *s1, char *s2);
int		load_file(t_data *sl, char *path);

#endif