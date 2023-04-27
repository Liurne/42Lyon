/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:23:38 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 17:24:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strber(const char *haystack)
{
	size_t	i;
	size_t	j;
	char	*ber;

	ber = ".ber\0";
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == ber[j] && ber[j] && haystack[i + j])
			j++;
		if (!ber[j] && !haystack[i + j])
			return (1);
		i++;
	}
	return (0);
}
