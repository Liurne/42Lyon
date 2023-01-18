/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:15 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/18 14:24:51 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst_a)
{
	int	a;
	int	b;
	int	c;

	a = (*lst_a)->content;
	b = (*lst_a)->next->content;
	c = (*lst_a)->next->next->content;
	if (a < b && b > c)
	{
		swap(lst_a, 'a');
		rotate(lst_a, 'a');
	}
	else if (a > b && b < c && a < c)
		swap(lst_a, 'a');
	else if (a < b && b > c)
		reverse(lst_a, 'a');
	else if (a > b && b < c)
		rotate(lst_a, 'a');
	else if (a > b && b > c)
	{
		swap(lst_a, 'a');
		reverse(lst_a, 'a');
	}
}

void	sort_five(t_list **lst_a, t_list **lst_b, size_t nbv)
{	
	smart_rotate(lst_a, 5, 0, 'a');
	push(lst_b, lst_a, 'b');
	if (nbv > 4)
	{
		smart_rotate(lst_a, 4, 1, 'a');
		push(lst_b, lst_a, 'b');
	}
	sort_three(lst_a);
	push(lst_a, lst_b, 'a');
	push(lst_a, lst_b, 'a');
}

void	sort_hundred(t_list **lst_a, t_list **lst_b, size_t nbv)
{
	size_t	val_bmedian;
	size_t	val_amedian;

	val_bmedian = 0;
	while (val_bmedian < nbv / 2)
	{
		if ((*lst_a)->content < nbv / 2)
		{
			push(lst_b, lst_a, 'b');
			val_bmedian++;
		}
		else
			rotate(lst_a, 'a');
	}
	sort_b(lst_a, lst_b, val_bmedian, 0);
	val_amedian = 0;
	while (val_amedian < nbv - val_bmedian)
	{
		push(lst_b, lst_a, 'b');
		val_amedian++;
	}
	sort_b(lst_a, lst_b, val_amedian, val_bmedian);
}

void	ft_sort(t_list **a, t_list **b, size_t nbv)
{
	if (nbv == 2)
		swap(a, 'a');
	else if (nbv == 3)
		sort_three(a);
	else if (nbv <= 5)
		sort_five(a, b, nbv);
	else
		sort_hundred(a, b, nbv);
}
