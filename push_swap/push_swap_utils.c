/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:57:49 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 13:39:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_val(int nbarg, char **values)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbarg)
	{
		j = i + 1;
		while (j < nbarg)
		{
			if (!ft_strcmp(values[i], values[j]))
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}
