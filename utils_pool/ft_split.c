/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:08:21 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/21 11:29:07 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char *str, char *charset, int p)
{
	int	i;

	i = 0;
	while (charset[i] && charset[i] != str[p])
		i++;
	if (charset[i] == '\0')
		return (0);
	return (1);
}

int	nb_word(char *str, char *charset)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			while (!is_sep(str, charset, i) && str[i] != '\0')
				i++;
		}
	}
	return (nb);
}

int	len_word(char *str, char *charset, int w)
{
	int	i;
	int	nb;
	int	l;

	i = 0;
	nb = 0;
	l = 0;
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			while (!is_sep(str, charset, i) && str[i] != '\0')
			{
				i++;
				if (nb == w)
					l++;
			}
		}
	}
	return (l);
}

char	*cpy_word(char *str, char *charset, int w, int i)
{
	int		j;
	int		nb;
	char	*word;

	nb = 0;
	word = (char *)malloc((len_word(str, charset, w) + 1) * sizeof(char));
	while (str[i])
	{
		while (is_sep(str, charset, i) && str[i] != '\0')
			i++;
		if (!is_sep(str, charset, i) && str[i] != '\0')
		{
			nb++;
			j = 0;
			while (!is_sep(str, charset, i) && str[i] != '\0')
			{
				if (w == nb)
					word[j] = str[i];
				j++;
				i++;
			}
		}
	}
	word[len_word(str, charset, w)] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		nbw;

	nbw = nb_word(str, charset);
	tab = (char **)malloc((nbw + 1) * sizeof(char *));
	i = -1;
	while (++i < nbw)
		tab[i] = cpy_word(str, charset, i + 1, 0);
	tab[i] = 0;
	return (tab);
}
