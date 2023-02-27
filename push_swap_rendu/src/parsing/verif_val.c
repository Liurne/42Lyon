/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:32:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 18:47:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(t_list **a, t_list **b)
{
	ft_putstr("Error\n", 2);
	if (a)
		ft_lstclear(a);
	if (b)
		ft_lstclear(b);
	return (1);
}

int	ft_isdouble(long int *tab, size_t index, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == tab[index] && i != index)
			return (1);
		i++;
	}
	return (0);
}

int	is_justspace(char *str)
{
	if (!str)
		return (0);
	while(*str)
	{
		if(*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	ft_issorted(t_list **lst)
{
	t_list *tmp;

	tmp = *lst;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
