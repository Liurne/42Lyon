/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:54:26 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/12 18:54:45 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	c = '0' + (nb % 10);
	if (nb != 0)
	{
		nb = nb / 10;
		ft_recursive(nb);
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
	else
		ft_recursive(nb);
}
