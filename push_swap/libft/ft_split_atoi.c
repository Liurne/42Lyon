/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:42:32 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/10 15:59:28 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_nbword(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (res);
}

void	*ft_abort(long int *tab, char *arg)
{
	free(tab);
	free(arg);
	return (NULL);
}

long int	*ft_split_atoi(char const *s, char c, size_t *nbV)
{
	size_t	i;
	size_t	j;
	long int	*res;
	char *tmp;

	j = 0;
	*nbV = ft_nbword(s, c);
	res = (long int *)malloc(sizeof(long int) * (*nbV));
	if (!res)
		return (NULL);
	while (j < *nbV)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		tmp = ft_substr(s, 0, i);
		if (!tmp || !ft_isnumber(tmp) || ft_strlen(tmp) > 11)
			return (ft_abort(res, tmp));
		res[j] = ft_atol(tmp);
		free(tmp);
		j++;
		s += i;
	}
	return (res);
}
