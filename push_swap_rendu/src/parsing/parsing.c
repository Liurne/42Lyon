/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:33 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 16:55:32 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_verif_val(long int *tab, size_t size)
{

}
int ft_loadlst(t_list **lst, long int *tab, size_t size)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < size)
	{
		tmp = ft_lstnew(ft_index(i, val, nbv));
		if (!tmp)
			return (1);
		ft_lstadd_back(l, tmp);
		i++;
	}
	return (0);
}

int	ft_load(t_list **lst, int ac, char **av)
{
	long int	*tab;
	size_t		nb_v;
	
	if(ac == 2)
		tab = ft_split_spe(av[1], tab, *nb_v);
	if(ac > 2)
		printf("test");
	else
		return (1);
	if (!tab)
		return (1);
	if	
	return (0);
}
