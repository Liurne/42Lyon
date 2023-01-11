/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 18:53:35 by jcoquard         ###   ########.fr       */
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

t_list	**create_list(void)
{
	t_list	**l;

	l = malloc(sizeof(t_list *));
	*l = NULL;
	return (l);
}

t_list	**ft_fill_list(size_t nbv, long int *val, t_list **l)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < nbv)
	{
		tmp = ft_lstnew((int)val[i]);
		if (!tmp)
		{
			ft_lstclear(l);
			return (l);
		}
		ft_lstadd_back(l, tmp);
		i++;
	}
	return (l);
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
	list_a = create_list();
	list_b = create_list();
	if (!list_a || !list_b)
		return (0);
	ft_fill_list(nb_val, arg, list_a);
	swap(list_a);
	printf("list a \n\n");
	tmp = *list_a;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("list b \n\n");
	tmp = *list_b;
	while (tmp)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	return (0);
}
