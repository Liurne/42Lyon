/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:47:08 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/14 18:18:34 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		nb = 1;
	else if (nb > 0)
		nb = nb * ft_recursive_factorial(nb - 1);
	else
		nb = 0;
	return (nb);
}
