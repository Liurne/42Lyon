/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:45:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/04 16:33:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_data *sl)
{
	if (keycode == 65307)
		close_window(sl);
	if (keycode == 103)
	{
		if (sl->show_hitbox)
			sl->show_hitbox = 0;
		else
			sl->show_hitbox = 1;
	}
	if ((keycode == 119 || keycode == 65362) && !sl->keys.left)
		sl->keys.left = 1;
	if ((keycode == 115 || keycode == 65364) && !sl->keys.right)
		sl->keys.right = 1;
	if ((keycode == 97 || keycode == 65361) && !sl->keys.down)
		sl->keys.down = 1;
	if ((keycode == 100 || keycode == 65363) && !sl->keys.up)
		sl->keys.up = 1;
	return (keycode);
}

int	key_release(int keycode, t_data *sl)
{
	if (keycode == 119 || keycode == 65362)
		sl->keys.left = 0;
	if (keycode == 115 || keycode == 65364)
		sl->keys.right = 0;
	if (keycode == 97 || keycode == 65361)
		sl->keys.down = 0;
	if (keycode == 100 || keycode == 65363)
		sl->keys.up = 0;
	return (keycode);
}
