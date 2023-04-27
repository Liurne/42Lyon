/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:37:46 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 18:27:14 by jcoquard         ###   ########.fr       */
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
# define ERR_MLX "Couldn't initiate mlx"
# define ERR_ARG "Invalid number of argument"
# define ERR_LIB "Couldn't create a window"
# define ERR_MAP "Map invalid or non-existant"
# define ERR_TEX "Texture invalid or non-existant"
# define ERR_IMG "Couldn't creater an image"

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

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

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
	int		id;
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
	t_entity	dog;
	int			anim;
	int			need_pet;
	int			show_hitbox;
}	t_data;

/* -----utils----- */
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strber(const char *haystack);

/* -----init----- */
int		init_window(t_data *sl, int win_w, int win_h);
int		close_window(t_data *sl);
int		new_img(t_data *sl, t_img *img, int w, int h);
int		load_img(t_data *sl, char *path, t_img *img);
int		destroy_img(t_data *sl, t_img *img);
void	load_all_image(t_data *sl);
void	destroy_all_image(t_data *sl);
int		error(t_data *sl, char *msg);

/* -----parsing----- */
int		load_map(t_data *sl, char *path);
int		verif_map(t_data *sl);
void	init_pos(t_data *sl);

/* -----world----- */
char	get_tile(t_data *sl, int x, int y);
int		set_tile(t_data *sl, int x, int y, char c);
int		is_still(char *map, char c);
void	init_pos(t_data *sl);
int		map_to_img(t_data *sl);
void	reload_tile_img(t_data *sl, int x, int y);

/* -----display----- */
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);
void	display_entity(t_data *sl, t_entity *e);
int		update_display(t_data *sl);

/* -----event----- */
int		event_manager(int keycode, t_data *sl);
void	dog_manager(t_data *sl, int r);
int		test_collision(t_data *sl, t_entity *e, int x, int y);
int		entity_collision(t_entity *e1, t_entity *e2);


#endif