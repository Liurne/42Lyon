/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:36:37 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/16 16:35:19 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (!*lst)
	{
		free(lst);
		return ;
	}
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	free(lst);
}
