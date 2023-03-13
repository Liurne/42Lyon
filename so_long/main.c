/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:54:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/13 14:32:36 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	main(void)
{
	t_data	so_long;

	init_window(&so_long);
	mlx_hook(so_long.win.win, 2, 1L << 0, event_manager, &so_long);
	mlx_hook(so_long.win.win, 17, 1L << 0, close_window, &so_long);
	mlx_loop(so_long.win.mlx);
	return (0);
}
