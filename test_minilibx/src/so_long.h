/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:26 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/30 11:56:16 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_wins
{
	void	*mlx;
	void	*win;
	void	*img;
}	t_wins;

typedef struct s_surface
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_surface;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rectangle
{
	t_point	pos;
	size_t	w;
	size_t	h;
}	t_rectangle;

typedef struct s_map
{
	size_t		nbtile_x;
	size_t		nbtile_y;
	size_t		tile_size;
	int			**map;
	t_surface	map_img;
}	t_map;

typedef struct s_data
{
	t_wins		*win;
	t_surface	*renderer;
	t_rectangle	*entity;
	t_map		*map;
}	t_data;

void	put_pixel(t_surface *img, int x, int y, int color);
void	draw_rectangle(t_surface *surf, t_rectangle rect, int color);
void	draw_rectanglef(t_surface *surf, t_rectangle rect, int color);

t_map	*map_init(void);

#endif