/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/29 14:42:56 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	main(int ac, char **av)
{
	t_data	so_long;

	init_window(&so_long);
	if (ac != 2 || !load_map(&so_long, av[1]))
		return (printf("fail\n"), 1);
	load_map_img(&so_long);
	load_pl_img(&so_long);
	map_to_img(&so_long);
	mlx_hook(so_long.win.win, 2, 1L << 0, event_manager, &so_long);
	mlx_hook(so_long.win.win, 17, 1L << 0, close_window, &so_long);
	mlx_loop_hook(so_long.win.mlx, update_display, &so_long);
	mlx_loop(so_long.win.mlx);
	return (0);
}
