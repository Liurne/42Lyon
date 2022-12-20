/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:24:14 by jcoquard          #+#    #+#             */
/*   Updated: 2022/12/02 17:40:44 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(const char *str, va_list ap)
{	
	if (*str == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (*str == '%')
		return (write(1, "%", 1));
	if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (*str == 'x')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	if (*str == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	if (*str == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_putnbr_hexa(
				(unsigned long long)va_arg(ap, void *), "0123456789abcdef"));
	}
	if (*str == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	nb;

	nb = 0;
	if (!str)
		return (0);
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			nb += ft_print_arg(str, ap);
		}
		else
			nb += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (nb);
}
