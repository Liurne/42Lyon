/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:33 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 17:18:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_index()

int	ft_loadlst(t_list **lst, long int *tab, size_t size)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] < -2147483648 || tab [i] > 2147483647
			|| ft_isdouble(tab, i, size))
			return (free(tab), 1);
		tmp = ft_lstnew(ft_index(i, tab[i], size));
		if (!tmp)
			return (free(tab), 1);
		ft_lstadd_back(lst, tmp);
		i++;
	}
	return (free(tab), 0);
}

int	ft_load(t_list **lst, int ac, char **av)
{
	long int	*tab;
	size_t		nb_v;

	if (ac == 2)
		tab = ft_split_spe(av[1], &nb_v);
	if (ac > 2)
		printf("test");
	else
		return (1);
	if (!tab)
		return (1);
	return (ft_loadlst(lst, tab, nb_v));
}
