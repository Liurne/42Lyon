/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 16:09:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_load(int nbA, char **val, size_t *nbV)
{
	long int	*res;
	char		*tmp;
	int			i;

	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	i = 1;
	while (i < nbA)
	{
		tmp = ft_strjoin(tmp, val[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	res = ft_split_atoi(tmp, ' ', nbV);
	free(tmp);
	return (res);
}

t_list	**ft_create_list(size_t nbv, long int *val)
{
	t_list	**res;
	t_list	*tmp1;
	t_list	*tmp2;
	size_t	i;

	tmp1 = NULL;
	res = &tmp1;
	i = 0;
	while (i < nbv)
	{
		tmp2 = ft_lstnew((int)val[i]);
		if (!tmp2)
		{
			ft_lstclear(res);
			return (res);
		}
		ft_lstadd_back(res, tmp2);
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	long int	*arg;	
	size_t		nb_val;
	t_list		**list_a;
	t_list		**list_b;
	t_list		*tmp;

	arg = ft_load(ac, av, &nb_val);
	if (!arg)
	{
		ft_putstr("Error\n");
		return (1);
	}
	list_b = NULL;
	list_a = ft_create_list(nb_val, arg);
	if (!list_a)
	{
		free(arg);
		ft_putstr("Error\n");
		return (0);
	}
	//pb(list_a, list_b);
	tmp = *list_a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	//ft_lstclear(list_a);
	free(arg);
	return (0);
}
