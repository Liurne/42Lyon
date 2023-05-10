/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:43:15 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 18:12:42 by jcoquard         ###   ########.fr       */
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
	if (a < b && b > c && a < c)
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
		val_bmedian += separate_val(lst_a, lst_b, nbv / 2, nbv / 4);
	sort_b(lst_a, lst_b, val_bmedian / 2, 0);
	sort_b(lst_a, lst_b, ft_lstsize(*lst_b), val_bmedian / 2);
	val_amedian = 0;
	while (val_amedian < nbv - val_bmedian)
		val_amedian += separate_val(lst_a, lst_b, nbv, (nbv / 4) * 3);
	sort_b(lst_a, lst_b, val_amedian / 2, val_bmedian);
	sort_b(lst_a, lst_b, ft_lstsize(*lst_b), val_bmedian + (val_amedian / 2));
}

void	sort_fivehundred(t_list **lst_a, t_list **lst_b, size_t nbv)
{
	size_t	chunk_bmedian;
	size_t	chunk_amedian;

	chunk_bmedian = 0;
	chunk_amedian = 0;
	while (chunk_bmedian < nbv / 2)
		chunk_bmedian += separate_val(lst_a, lst_b, nbv / 2, nbv / 4);
	fh_first_chunk(lst_a, lst_b, chunk_bmedian, 0);
	sort_b(lst_a, lst_b, chunk_bmedian / 4, 0);
	sort_b(lst_a, lst_b, chunk_bmedian / 4, ft_lstlast(*lst_a)->content + 1);
	fh_second_chunk(lst_a, lst_b, chunk_bmedian, 0);
	sort_b(lst_a, lst_b, chunk_bmedian / 4, ft_lstlast(*lst_a)->content + 1);
	sort_b(lst_a, lst_b, ft_lstsize(*lst_b), ft_lstlast(*lst_a)->content + 1);
	while (chunk_amedian < nbv - chunk_bmedian)
		chunk_amedian += separate_val(lst_a, lst_b, nbv, (nbv / 4) * 3);
	fh_first_chunk(lst_a, lst_b, chunk_amedian, chunk_bmedian);
	sort_b(lst_a, lst_b, chunk_amedian / 4, ft_lstlast(*lst_a)->content + 1);
	sort_b(lst_a, lst_b, chunk_amedian / 4, ft_lstlast(*lst_a)->content + 1);
	fh_second_chunk(lst_a, lst_b, chunk_amedian, chunk_bmedian);
	sort_b(lst_a, lst_b, chunk_amedian / 4, ft_lstlast(*lst_a)->content + 1);
	sort_b(lst_a, lst_b, ft_lstsize(*lst_b), ft_lstlast(*lst_a)->content + 1);
}

void	ft_sort(t_list **a, t_list **b, size_t nbv)
{
	if (nbv == 2)
		swap(a, 'a');
	else if (nbv == 3)
		sort_three(a);
	else if (nbv <= 5)
		sort_five(a, b, nbv);
	else if (nbv <= 100)
		sort_hundred(a, b, nbv);
	else
		sort_fivehundred(a, b, nbv);
}	
