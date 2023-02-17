/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_beforelast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:56:05 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/14 13:59:36 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}
