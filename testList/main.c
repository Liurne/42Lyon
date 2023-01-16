/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:11:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 17:49:04 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	**create_table(void)
{
	t_list	**l;
	t_list	*tmp;

	l = malloc(sizeof(t_list *));
	*l = NULL;
	return (l);
}

int	main(int ac, char **av)
{
	t_list	**l1;
	t_list	**l2;
	t_list	*tmp;
	t_list	*tt;
	size_t	i;
	int t;

	i = 1;
	l1 = create_table();
	l2 = create_table();
	while (i < 10)
	{
		tmp = ft_lstnew(i);
		if (!tmp)
			return (0);
		ft_lstadd_back(l1, tmp);
		i++;
	}
	if (*l1)
	tt = *l1;
	while (tt && t != tt->content)
	{
		printf("%d\n", tt->content);
		t = tt->content;
		tt = tt->next;
	}
	ft_lstclear(l1);
	//ft_lstclear(l2);
	return (0);
}