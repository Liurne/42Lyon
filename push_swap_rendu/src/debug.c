/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:41:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/24 17:43:36 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printTab(long int *tab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		printf("tab[%lu]:%ld \n", i, tab[i]);
		i++;
	}
}

void printlst(t_list **a, t_list **b)
{
	t_list	*ta;
	t_list	*tb;

	ta = *a;
	tb = *b;
	printf("lst a:  lst b:\n");
	while (ta || tb)
	{
		if (ta)
		{
			printf("%lu\t\t", ta->content);
			ta = ta->next;
		}
		if (tb)
		{
			printf("%lu",tb->content);
		}
		printf("\n");
		
		
	}
}