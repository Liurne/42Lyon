/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:44 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/17 14:52:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **lst, char c)
{
	t_list	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	ft_lstlast(*lst)->next = tmp;
	if (c == 'a')
		ft_putstr("ra\n");
	if (c == 'b')
		ft_putstr("rb\n");
}

void rotateboth(t_list **l1, t_list **l2)
{
	rotate(l1, '\0');
	rotate(l2, '\0');
	ft_putstr("rr\n");
}
