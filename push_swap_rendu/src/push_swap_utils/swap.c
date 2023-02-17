/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:47 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/21 16:22:43 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **lst, char c)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	if (c == 'a')
		ft_putstr("sa\n", 1);
	if (c == 'b')
		ft_putstr("sb\n", 1);
}

void	swapboth(t_list **l1, t_list **l2)
{
	swap(l1, '\0');
	swap(l2, '\0');
	ft_putstr("ss\n", 1);
}
