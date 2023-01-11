/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:30:40 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/18 11:45:03 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*res;
	int		l;

	l = 0;
	while (src[l])
		l++;
	res = (char *)malloc((l + 1) * sizeof(char));
	l = 0;
	while (src[l])
	{
		res [l] = src[l];
		l++;
	}
	res[l] = '\0';
	return (res);
}
