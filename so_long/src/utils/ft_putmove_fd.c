/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmove_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:57:52 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/03 15:38:39 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putmove_fd(int nb_move, int fd)
{
	ft_putstr_fd("Number of tiles traveled : ", fd);
	ft_putnbr_fd(nb_move, fd);
	ft_putstr_fd("\n", fd);
}
