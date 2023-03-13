/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:14:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/13 14:48:01 by jcoquard         ###   ########.fr       */
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

typedef struct s_surface
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_surface;

typedef struct s_wins
{
	void		*mlx;
	void		*win;
	t_surface	renderer;
}	t_wins;

typedef struct s_img
{
	int		img_w;
	int		img_h;
	void	*img;
}	t_img;

typedef struct s_data
{
	t_wins		win;
	t_surface	renderer;
	t_img		player;
}	t_data;

/* -----window----- */
int	close_window(t_data *sl);
int	init_window(t_data *sl);

/* -----event----- */
int	event_manager(int keycode, t_data *sl);
#endif