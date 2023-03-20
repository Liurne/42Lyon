/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/20 17:43:42 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	main(void)
{
	t_data	so_long;

	init_window(&so_long);
	load_map_img(&so_long);
	load_pl_img(&so_long);
	load_map_img(&so_long);
	so_long.map.map = (char *)malloc(sizeof(char) * 117);
	so_long.map.map = "111111111111\n100001000001\n100001000001\n100000000001\n100000000001\n100000000001\n100000100001\n100000100001\n111111111111\0";
	so_long.map.height = 9;
	so_long.map.width = 12;
	so_long.map.pos.x = 0;
	so_long.map.pos.y = 0;
	so_long.pl.pos.x = 64;
	so_long.pl.pos.y = 64;
	so_long.pl.dir = 0;
	so_long.pl.nb_mv = 0;
	map_to_img(&so_long);
	mlx_hook(so_long.win.win, 2, 1L << 0, event_manager, &so_long);
	mlx_hook(so_long.win.win, 17, 1L << 0, close_window, &so_long);
	mlx_loop_hook(so_long.win.mlx, update_display, &so_long);
	mlx_loop(so_long.win.mlx);
	return (0);
}
