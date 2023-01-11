/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:14:49 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/19 13:57:56 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strfulllen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;
	int	lensep;

	if (size == 0)
		return (1);
	lensep = 0;
	while (sep[lensep])
		lensep++;
	i = 0;
	len = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			len++;
			j++;
		}
		i++;
	}
	i--;
	return (size + (i * lensep));
}

void	add_sep(char *str, int *pos, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		str[*pos] = sep[i];
		*pos += 1;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = -1;
	res = (char *)malloc(strfulllen(size, strs, sep) * sizeof(char));
	if (size != 0)
	{
		while (++j < size)
		{
			k = -1;
			while (strs[j][++k])
			{
				res [i] = strs[j][k];
				i++;
			}
			if (j < size - 1)
				add_sep(res, &i, sep);
		}
	}
	res[i] = '\0';
	return (res);
}
