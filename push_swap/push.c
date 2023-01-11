/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:41 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 18:54:05 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp;

	if ((*src))
	{
		tmp_a = *dst;
		tmp_b = *src;
		tmp = tmp_b->next;
		*dst = tmp_b;
		(*src)->next = tmp_a;
		if (!tmp)
			*src = NULL;
		else
			*src = tmp;
	}
}
