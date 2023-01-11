/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:42:16 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/14 16:42:09 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(long int nbr, char *base, int l)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr > 1)
		ft_print(nbr / l, base, l);
	write(1, &base[nbr % l], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;
	int	i;

	l = 0;
	i = -1;
	while (base[l] && (i == -1 || base[i] == '\0'))
	{
		i = l + 1;
		while (base[i] && base[i] != base[l])
			i++;
		l++;
	}
	if (l > 1 && base[l] == '\0' && base[i] == '\0')
		ft_print(nbr, base, l);
}
