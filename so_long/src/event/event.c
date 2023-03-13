/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/03/13 14:29:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	event_manager(int keycode, t_data *sl)
{
	printf("keycode:%d\n", keycode);
	if (keycode == 65307)
		close_window(sl);
	if (keycode == 119)
		printf("up\n");
	if (keycode == 115)
		printf("down\n");
	if (keycode == 97)
		printf("left\n");
	if (keycode == 100)
		printf("right\n");
	return (keycode);
}
