/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:58:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/04 17:07:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	move_dog(t_data *sl, t_entity *e, int x, int y)
{
	if (!test_collision(sl, e, x, y))
	{
		e->pos.x += x;
		e->pos.y += y;
	}
	else
	{
		e->dir += 2;
		if (e->dir > 3)
			e->dir -= 4;
	}
	return (0);
}

static void	dog_pet(t_data *sl, t_entity *e)
{
	ft_putstr_fd("NEED...TO...PEEEEEEEET!!\n", 1);
	ft_putstr_fd("You lost 100 moves\n", 1);
	sl->need_pet = 0;
	e->inmove = 0;
	e->dir = 4;
	e->animation = 0;
	e->pos.x = sl->pl.pos.x;
	e->pos.y = sl->pl.pos.y;
	sl->pl.nb_mv += 100;
	sl->pl.dir = 4;
	sl->pl.animation = 0;
	sl->pl.inmove = 0;
}

static void	dog_action(t_data *sl, t_entity *e, int time)
{
	if (e->inmove && !(time % 3))
	{
		if (e->dir == 0)
			move_dog(sl, e, 0, 10);
		if (e->dir == 1)
			move_dog(sl, e, 0, -10);
		if (e->dir == 2)
			move_dog(sl, e, 10, 0);
		if (e->dir == 3)
			move_dog(sl, e, -10, 0);
	}
	if (entity_collision(&(sl->pl), e) && sl->need_pet >= 275)
		dog_pet(sl, e);
}

void	dog_manager(t_data *sl, t_entity *e)
{
	static int	time;
	static int	r;

	if (sl->need_pet > 200)
	{
		if (time > 100)
		{
			time = 0;
			r += (sl->pl.pos.x + sl->pl.pos.y + sl->pl.d + sl->time + e->id);
			if (r % 3 == 0)
				e->inmove = 0;
			else
				e->inmove = 1;
			e->dir = (r % 4);
		}
		if (sl->need_pet < 275 && e->id == 1 && time % 8)
			sl->need_pet++;
		dog_action(sl, e, time);
	}
	else if (e->id == 1)
		sl->need_pet++;
	time++;
}
