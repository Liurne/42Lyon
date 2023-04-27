/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 18:33:04 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_dog(t_data *sl, int x, int y)
{
	if (!test_collision(sl, &(sl->dog), x, y))
	{
		sl->dog.pos.x += x;
		sl->dog.pos.y += y;
	}
	else
	{
		sl->dog.dir += 2;
		if (sl->dog.dir > 3)
			sl->dog.dir -= 4;
	}
	return (0);
}

void	dog_action(t_data *sl, int time)
{
	if (sl->dog.inmove && !(time % 3))
	{
		if (sl->dog.dir == 0)
			move_dog(sl, 0, 16);
		if (sl->dog.dir == 1)
			move_dog(sl, 0, -16);
		if (sl->dog.dir == 2)
			move_dog(sl, 16, 0);
		if (sl->dog.dir == 3)
			move_dog(sl, -16, 0);
		if (entity_collision(&(sl->pl), &(sl->dog)) && sl->need_pet == 201)
		{
			ft_putstr_fd("need...to...peeeeeet\n", 1);
			sl->need_pet = 0;
			sl->dog.inmove = 0;
			sl->dog.pos.x = sl->pl.pos.x;
			sl->dog.pos.y = sl->pl.pos.y;
			sl->pl.nb_mv += 100;
			sl->pl.dir = 1;
			sl->pl.inmove = 0;
			time = 0;
		}
	}
}

void	dog_manager(t_data *sl, int r)
{
	static int	time;

	if (sl->need_pet > 200)
	{
		if (time > 100)
		{
			time = 0;
			sl->need_pet = 201;
			r = (sl->pl.pos.x + sl->pl.pos.y + sl->pl.d + r);
			if (r % 3 == 0)
				sl->dog.inmove = 0;
			else
				sl->dog.inmove = 1;
			sl->dog.dir = (r % 4);
		}
		dog_action(sl, time);
	}
	else
		sl->need_pet++;
	time++;
}
