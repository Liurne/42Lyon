/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/18 14:25:59 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_issorted(size_t nbv, long int *values)
{
	size_t	i;
	int		is_sorted;

	i = 1;
	is_sorted = 1;
	while (i < nbv && is_sorted)
	{
		if (values[i - 1] > values[i])
			is_sorted = 0;
		i++;
	}
	return (is_sorted);
}

int	value_by_index(size_t i, t_list **l)
{
	t_list	*tmp;

	tmp = *l;
	while (i > 0 && tmp->next)
	{
		tmp = tmp->next;
		i--;
	}
	return (tmp->content);
}

size_t	index_by_value(size_t value, t_list **l)
{
	t_list	*tmp;
	size_t	i;

	tmp = *l;
	i = 0;
	while (tmp->content != value && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->content != value)
		return (0);
	return (i);
}
