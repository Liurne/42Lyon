/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_spe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:42:32 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 16:50:53 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_nbword(char const *s)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] && (s[i] != ' '))
			i++;
	}
	return (res);
}

static int	ft_getvalue(int *tab, int wrd, int bwrd, int lwrd)
{
	char	*val;

	val = ft_substr(bwrd, 0, lwrd);
	if (!val)
		return (1);
	if (!ft_isnumber(val) || ft_strlen(val) > 11)
		return (free(val), 1);
	tab[wrd] = ft_atol(val);
	return (free(val), 0);
}

int	*ft_split_spe(char const *s, size_t *n)
{
	size_t		i;
	size_t		j;
	long int	*tab;

	j = 0;
	*n = ft_nbword(s);
	tab = (long int *)malloc(sizeof(long int) * (*n + 1));
	if (!tab)
		return (NULL);
	while (j < *n)
	{
		while (*s == ' ')
			s++;
		i = 0;
		while (s[i] && s[i] != ' ')
			i++;
		if (ft_getvalue(tab, j, s, i))
			return (free(tab), NULL);
		j++;
		s += i;
	}
	return (tab);
}
