/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:08:00 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/24 13:47:49 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(l * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[l - 1] = '\0';
	return (res);
}
