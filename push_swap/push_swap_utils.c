/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/03 17:22:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_val(int nbarg, char **value)
{
	int	i;
	int	j;
	
	if (nbarg <= 1)
		return (0);
	i = 1;
	while (i < nbarg)
	{
		if (!ft_isnumber(value[i]))
			return (0);
		else
		{
			j = 1;
			if (i == j)
				j++;
			while (j < nbarg && ft_strcmp(value[i], value[j]))
			{
				j++;
				if (i == j)
					j++;
			}
			if (j < nbarg)
				return (0);
		}
		i++;
	}	
	return (1);
}

int	verif_arg(char *str)
{
	char **tmp;

	tmp = ft_split(str,' ');
}