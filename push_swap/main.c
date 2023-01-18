/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/18 16:02:16 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_afflst(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("%ld\n", tmp->content);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	long int	*arg;	
	size_t		nb_val;
	t_list		**list_a;
	t_list		**list_b;

	arg = ft_load(ac, av, &nb_val);
	if (!arg)
		return (1);
	list_a = ft_lstinit();
	if (!list_a)
	{
		free(arg);
		return (0);
	}	
	list_b = ft_lstinit();
	if (!list_b)
	{
		free(arg);
		ft_lstclear(list_a);
		return (0);
	}
	ft_fill_list(nb_val, arg, list_a);
	ft_sort(list_a, list_b, nb_val);
	/*printf("list a :\n");
	ft_afflst(list_a);
	printf("list b :\n");
	ft_afflst(list_b);
	printf("nbv: %ld\n", nb_val);*/
	free(arg);
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	return (0);
}
