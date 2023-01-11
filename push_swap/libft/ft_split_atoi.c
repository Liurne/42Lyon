/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:42:32 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/11 13:43:39 by jcoquard         ###   ########.fr       */
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

void	*ft_abort(long int *tab, char **arg, size_t *nbv)
{
	ft_free(arg, *nbv);
	free(tab);
	return (NULL);
}

void	*ft_free(char **tab, size_t nbword)
{
	while (nbword)
	{
		free(tab[nbword]);
		nbword--;
	}
	free(tab[nbword]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c, size_t *nbv)
{
	size_t	i;
	size_t	j;
	char	**res;

	j = 0;
	*nbv = ft_nbword(s, c);
	res = (char **)malloc(sizeof(char *) * (*nbv + 1));
	if (!res)
		return (NULL);
	while (j < *nbv)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		res[j] = ft_substr(s, 0, i);
		if (!res[j])
			return (ft_free(res, j));
		j++;
		s += i;
	}
	res[j] = NULL;
	return (res);
}

long int	*ft_split_atoi(char const *s, char c, size_t *nbv)
{
	char		**tmp;
	long int	*res;
	size_t		i;

	tmp = ft_split(s, c, nbv);
	if (!tmp)
		return (NULL);
	res = (long int *)malloc(sizeof(long int) * (*nbv));
	if (!res)
		return (ft_free(tmp, *nbv));
	i = 0;
	while (i < *nbv)
	{
		if (!ft_isnumber(tmp[i]) || ft_strlen(tmp[i]) > 11)
			return (ft_abort(res, tmp, nbv));
		res[i] = ft_atol(tmp[i]);
		if (res[i] > INT_MAX || res[i] < INT_MIN)
			return (ft_abort(res, tmp, nbv));
		i++;
	}
	if (!verif_val(*nbv, tmp))
		return (ft_abort(res, tmp, nbv));
	ft_free(tmp, *nbv);
	return (res);
}
