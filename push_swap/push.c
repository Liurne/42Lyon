/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:41 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 15:55:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp;

	if ((*b))
	{
		tmp_a = *a;
		tmp_b = *b;
		tmp = tmp_b->next;
		*a = tmp_b;
		(*a)->next = tmp_a;
		if (!tmp)
			*b = NULL;
		else
			*b = tmp;
		ft_putstr("pa\n");
	}
}
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp;

	if ((*a))
	{
		tmp_b = *b;
		tmp_a = *a;
		tmp = tmp_a->next;
		*b = tmp_a;
		(*b)->next = tmp_b;
		if (!tmp)
			*a = NULL;
		else
			*a = tmp;
		ft_putstr("pb\n");
	}
}