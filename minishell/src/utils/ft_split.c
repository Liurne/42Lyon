/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:20:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/11 17:24:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	*ft_free(char **tab, size_t nbword)
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	**res;

	j = 0;
	n = ft_nbword(s, c);
	res = (char **)malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (NULL);
	while (j < n)
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