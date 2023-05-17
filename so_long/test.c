/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:54:48 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/17 14:55:35 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (x != 0 && sl->pl.pos.x >= sl->win.w / 2 && ((sl->map.w * 128) - sl->pl.pos.x) > sl->win.w / 2)
	if (sl->map.pos.x - x <= 0 && sl->map.pos.x - x - sl->win.w >= sl->map.w * -128)
		sl->map.pos.x -= x;
if (y != 0 && sl->pl.pos.y >= sl->win.h / 2 && ((sl->map.h * 128) - sl->pl.pos.y) > sl->win.h / 2)
	if (sl->map.pos.y - y <= 0 && sl->map.pos.y - y - sl->win.h >= sl->map.h * -128)
		sl->map.pos.y -= y;