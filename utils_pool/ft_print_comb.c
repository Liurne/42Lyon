/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:31:31 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/06 20:40:35 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_verif_print(char n1, char n2, char n3)
{
	if (n1 < n2 && n2 < n3)
	{
		write(1, &n1, 1);
		write(1, &n2, 1);
		write(1, &n3, 1);
		if (n1 != '7' || n2 != '8' || n3 != '9')
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = '0';
	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '9')
		{
			n3 = '0';
			while (n3 <= '9')
			{
				ft_verif_print(n1, n2, n3);
				n3++;
			}
			n2++;
		}
		n1++;
	}
}
