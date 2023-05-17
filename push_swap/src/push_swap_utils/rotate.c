/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:44 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/21 16:22:29 by jcoquard         ###   ########.fr       */
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
		ft_putstr("ra\n", 1);
	if (c == 'b')
		ft_putstr("rb\n", 1);
}

void	rotateboth(t_list **l1, t_list **l2)
{
	rotate(l1, '\0');
	rotate(l2, '\0');
	ft_putstr("rr\n", 1);
}