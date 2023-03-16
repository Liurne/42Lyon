/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/16 16:45:39 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	event_manager(int keycode, t_data *sl)
{
	printf("keycode:%d\n", keycode);
	if (keycode == 65307)
		close_window(sl);
	if (keycode == 119)
	{
		printf("up\n");
		sl->pl.pos.y--;
	}
	if (keycode == 115)
	{
		printf("down\n");
		sl->pl.pos.y++;
	}	
	if (keycode == 97)
	{
		printf("left\n");
		sl->pl.pos.x--;
	}
	if (keycode == 100)
	{
		printf("right\n");
		sl->pl.pos.x++;
	}
	return (keycode);
}
