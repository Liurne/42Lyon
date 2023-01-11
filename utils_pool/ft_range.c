/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:53:39 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/18 13:25:39 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	size;
	int	i;

	size = max - min;
	if (min >= max)
		return (NULL);
	res = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
