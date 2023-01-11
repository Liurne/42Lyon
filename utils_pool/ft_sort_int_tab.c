/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:26:40 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/07 12:54:58 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_compare(int *tab, int j, int *t, int *p)
{
	if (*t > tab[j])
	{
		tab[*p] = tab[j];
		tab[j] = *t;
		*p = j;
	}
	else
	{
		*p = j;
		*t = tab[j];
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	t;
	int	p;

	i = 0;
	while (i < size)
	{	
		p = 0;
		t = tab[0];
		j = 0;
		while (j < size - i)
		{
			ft_compare(tab, j, &t, &p);
			j++;
		}
		i++;
	}
}
