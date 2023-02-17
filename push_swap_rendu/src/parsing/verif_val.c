/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:32:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 16:08:25 by jcoquard         ###   ########.fr       */
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

