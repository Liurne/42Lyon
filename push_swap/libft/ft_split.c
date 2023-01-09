/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:42:32 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/09 16:44:18 by jcoquard         ###   ########.fr       */
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

char	**ft_split(char const *s, char c, size_t *nbV)
{
	size_t	i;
	size_t	j;
	char	**res;

	j = 0;
	*nbV = ft_nbword(s, c);
	res = (char **)malloc(sizeof(char *) * (*nbV + 1));
	if (!res)
		return (NULL);
	while (j < *nbV)
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
