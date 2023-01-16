/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:21:47 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/14 14:28:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}
