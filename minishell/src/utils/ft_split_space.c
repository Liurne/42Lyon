/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:22:50 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/11 18:13:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_nbword(char const *s)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (ft_iswhitespace(s[i]))
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] && !ft_iswhitespace(s[i]))
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

char	**ft_split_space(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	**res;

	j = 0;
	n = ft_nbword(s);
	res = (char **)malloc(sizeof(char *) * (n + 1));
	if (!res)
		return (NULL);
	while (j < n)
	{
		while (ft_iswhitespace(*s))
			s++;
		i = 0;
		while (s[i] && !ft_iswhitespace(s[i]))
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