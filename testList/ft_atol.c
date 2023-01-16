/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:19:14 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 16:20:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

long int	ft_atol(const char *str)
{
	size_t		i;
	long int	m;
	long int	res;

	res = 0;
	i = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * m);
}
