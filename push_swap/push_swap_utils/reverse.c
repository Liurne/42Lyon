/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:25:31 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/14 14:28:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_list **lst)
{
	t_list	*tmp;

	if (!*lst && !(*lst)->next)
		return ;
	tmp = ft_lstlast(*lst);
	ft_lstbeforelast(*lst)->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
}
