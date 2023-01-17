/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/17 12:37:00 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_afflst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

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
