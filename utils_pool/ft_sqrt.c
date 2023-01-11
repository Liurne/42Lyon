/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:37:20 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/17 14:19:42 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	x;

	if (x >= 0)
	{
		x = 0;
		while (x * x != nb && x < nb)
			x++;
		if (x * x == nb)
			return (x);
	}
	return (0);
}
