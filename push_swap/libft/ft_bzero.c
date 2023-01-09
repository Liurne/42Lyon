/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:52:18 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/05 16:00:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (++i < n + 1)
		((char *) s)[i - 1] = '\0';
}
