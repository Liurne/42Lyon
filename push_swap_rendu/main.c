/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:43 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap.h"

int	main(int ac, char **av)
{
	t_list		**list_a;
	t_list		**list_b;

	list_a = ft_lstinit();
	if (!list_a)
		return (1);
	list_b = ft_lstinit();
	if (!list_b)
		return (ft_lstclear(list_a), 1);
	if (ft_load(list_a, ac, av))
		return (ft_error(list_a, list_b));
	if (!ft_issorted(list_a))
		ft_sort(list_a, list_b, ft_lstsize(*list_a));
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	return (0);
}
