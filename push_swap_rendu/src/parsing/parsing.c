/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:33 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 19:50:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_index(size_t index, long int *tab, size_t size)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		if (tab[i] < tab[index])
			res++;
		i++;
	}
	return (res);
}

static int	ft_loadlst(t_list **lst, long int *tab, size_t size)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] < -2147483648 || tab[i] > 2147483647
			|| ft_isdouble(tab, i, size))
			return (free(tab), 1);
		tmp = ft_lstnew(ft_index(i, tab, size));
		if (!tmp)
			return (free(tab), 1);
		ft_lstadd_back(lst, tmp);
		i++;
	}
	return (free(tab), 0);
}

static long int	*ft_multi_arg(int ac, char **av, size_t *size)
{
	long int	*res;
	int	i;

	*size = ac - 1;
	res = (long int*)malloc(sizeof(long int) * (ac - 1));
	if (!res)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (!av[i] || !ft_isnumber(av[i]) ||
				ft_strlen(av[i]) > 11 || is_justspace(av[i]))
			return(free(res), NULL);
		res[i - 1] = ft_atol(av[i]);
		i++;
	}
	return (res);
}

int	ft_load(t_list **lst, int ac, char **av)
{
	long int	*tab;
	size_t		nb_v;

	if (ac == 2)
		tab = ft_split_spe(av[1], &nb_v);
	else if (ac > 2)
		tab = ft_multi_arg(ac, av, &nb_v);
	else
		return (1);
	if (!tab)
		return (1);
	return (ft_loadlst(lst, tab, nb_v));
}
