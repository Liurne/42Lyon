/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/18 00:51:52 by jcoquard         ###   ########.fr       */
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
	
	tmp =  *l;
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

void	smart_rotate(t_list **lst, size_t nbv, size_t val, char c)
{
	size_t	tmp;
	
	tmp = index_by_value(val, lst);
	/*printf("index: %ld, len: %ld , median: %ld, val: %ld, reel val:%d\n", tmp, nbv, nbv/2, val, value_by_index(tmp,lst));
	ft_afflst(lst);
	printf("end\n");*/
	if (tmp > nbv/2)
		while ((*lst)->content != val)
			reverse(lst, c);
	else
		while ((*lst)->content != val)
			rotate(lst, c);
}

void	sort_b(t_list **lst_a, t_list **lst_b, size_t count, size_t svalue)
{
	size_t tmp;
	
	tmp = 0;
	
	while (tmp < count)
	{
		smart_rotate(lst_b, count - tmp, svalue + tmp, 'b');
		push(lst_a, lst_b, 'a');
		rotate(lst_a, 'a');
		tmp++;
	}
}