/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:31 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/21 16:22:13 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_list **lst, char c)
{
	t_list	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = ft_lstlast(*lst);
	ft_lstbeforelast(*lst)->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	if (c == 'a')
		ft_putstr("rra\n", 1);
	if (c == 'b')
		ft_putstr("rrb\n", 1);
}

void	reverseboth(t_list **l1, t_list **l2)
{
	reverse(l1, '\0');
	reverse(l2, '\0');
	ft_putstr("rrr\n", 1);
}
