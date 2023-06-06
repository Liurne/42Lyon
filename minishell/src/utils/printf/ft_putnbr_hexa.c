/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:53 by jcoquard          #+#    #+#             */
/*   Updated: 2022/12/02 17:10:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putnbr_hexa(nbr / 16, base);
		len += ft_putnbr_hexa(nbr % 16, base);
	}
	else
		len += write(1, &base[nbr % 16], 1);
	return (len);
}
