/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:41:05 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/16 17:25:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	**ft_lstinit(void)
{
	t_list	**l;

	l = malloc(sizeof(t_list *));
	*l = NULL;
	return (l);
}
