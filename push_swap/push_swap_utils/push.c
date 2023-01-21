/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:41 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/21 16:22:01 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **dst, t_list **src, char c)
{
	t_list	*tmp_d;
	t_list	*tmp_s;
	t_list	*tmp;

	if ((*src))
	{
		tmp_d = *dst;
		tmp_s = *src;
		tmp = tmp_s->next;
		*dst = tmp_s;
		(*src)->next = tmp_d;
		if (!tmp)
			*src = NULL;
		else
			*src = tmp;
		if (c == 'a')
			ft_putstr("pa\n", 1);
		if (c == 'b')
			ft_putstr("pb\n", 1);
	}
}
