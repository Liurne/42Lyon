/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:12:20 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/06 20:42:25 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char n1, char n2, char n3, char n4)
{
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, " ", 1);
	write(1, &n3, 1);
	write(1, &n4, 1);
	if (n1 != '9' || n2 != '8' || n3 != '9' || n4 != '9')
	{
		write(1, ", ", 2);
	}	
}

void	ft_verif(char d1, char u1, char d2, char u2)
{
	if (d1 < d2)
	{
		ft_print(d1, u1, d2, u2);
	}
	else if (d1 == d2)
	{
		if (u1 < u2)
		{
			ft_print(d1, u1, d2, u2);
		}
	}
}

void	ft_boucle(char n1, char n2, char n3, char n4)
{
	n1 = '0';
	while (n1 <= '9')
	{
		n2 = '0';
		while (n2 <= '9')
		{
			n3 = '0';
			while (n3 <= '9')
			{
				n4 = '0';
				while (n4 <= '9')
				{
					ft_verif(n1, n2, n3, n4);
					n4++;
				}
				n3++;
			}
			n2++;
		}
		n1++;
	}
}

void	ft_print_comb2(void)
{
	char	n1;
	char	n2;
	char	n3;
	char	n4;

	n1 = '0';
	n2 = '0';
	n3 = '0';
	n4 = '0';
	ft_boucle(n1, n2, n3, n4);
}
