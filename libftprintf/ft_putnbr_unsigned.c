/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:14:41 by jcoquard          #+#    #+#             */
/*   Updated: 2022/12/02 16:28:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	size_t	c;
	int		s;

	c = 0;
	s = 0;
	if (n > 9)
		s += ft_putnbr(n / 10);
	c = '0' + n % 10;
	return (s += write(1, &c, 1));
}
