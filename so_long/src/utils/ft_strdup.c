/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:58:50 by jcoquard          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:03 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	l;
	size_t	i;

	l = 0;
	while (s[l])
		l++;
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && l != 0)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}
