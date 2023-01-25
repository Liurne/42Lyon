/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:32:07 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/25 17:41:50 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	smart_rotate(t_list **lst, size_t nbv, size_t val, char c)
{
	size_t	tmp;

	tmp = index_by_value(val, lst);
	if (tmp > nbv / 2)
		while ((*lst)->content != val)
			reverse(lst, c);
	else
		while ((*lst)->content != val)
			rotate(lst, c);
}

int	closer_val(t_list **lst, size_t val1, size_t val2, size_t size)
{
	size_t	id1;
	size_t	id2;

	id1 = index_by_value(val1, lst);
	id2 = index_by_value(val2, lst);
	if (id1 > size / 2)
		id1 = size - id1;
	if (id2 > size / 2)
		id2 = size - id2;
	if (id1 < id2)
		return (val1);
	return (val2);
}

size_t	separate_val(t_list **la, t_list **lb, size_t lim1, size_t lim2)
{
	if ((*la)->content < lim1)
	{
		push(lb, la, 'b');
		if ((*lb) && (*lb)->next && (*lb)->content > lim2)
			rotate(lb, 'b');
		return (1);
	}
	else
	{
		rotate(la, 'a');
		return (0);
	}
}

void	sort_b(t_list **lst_a, t_list **lst_b, size_t size, size_t sval)
{
	size_t	tmp;
	size_t	val;
	size_t	vmax;

	tmp = 0;
	vmax = size;
	while (tmp < vmax)
	{
		val = closer_val(lst_b, sval + tmp, sval + vmax - 1,
				ft_lstsize(*lst_b));
		smart_rotate(lst_b, ft_lstsize(*lst_b), val, 'b');
		push(lst_a, lst_b, 'a');
		if (val == sval + tmp)
		{
			rotate(lst_a, 'a');
			tmp++;
		}
		else
			vmax--;
	}
	while (vmax < size)
	{
		rotate(lst_a, 'a');
		vmax++;
	}
}
