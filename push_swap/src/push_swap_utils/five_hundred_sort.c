/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_hundred_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:41:27 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/25 17:43:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fh_first_chunk(t_list **a, t_list **b, size_t nbv, size_t s_val)
{
	size_t	chunk;
	size_t	tmp;

	chunk = 0;
	while ((*b)->content < s_val + (nbv / 2) || chunk < nbv / 4)
	{
		if ((*b)->content < s_val + (nbv / 4))
		{
			push(a, b, 'a');
			chunk++;
		}
		else
			rotate(b, 'b');
	}
	tmp = chunk;
	while (tmp)
	{
		push(b, a, 'b');
		tmp--;
	}
}

void	fh_second_chunk(t_list **a, t_list **b, size_t nbv, size_t s_val)
{
	size_t	chunk;
	size_t	tmp;

	chunk = 0;
	while (chunk < nbv / 4)
	{
		if ((*b)->content < s_val + (nbv / 4) * 3)
		{
			push(a, b, 'a');
			chunk++;
		}
		else
			rotate(b, 'b');
	}
	tmp = chunk;
	while (tmp)
	{
		push(b, a, 'b');
		tmp--;
	}
}
