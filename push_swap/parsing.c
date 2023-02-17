/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:33 by jcoquard          #+#    #+#             */
/*   Updated: 2023/02/17 16:22:57 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verif_val(int nbarg, char **values)
{
	int	i;
	int	j;

	i = 0;
	while (i < nbarg)
	{
		j = i + 1;
		while (j < nbarg)
		{
			if (!ft_strcmp(values[i], values[j]))
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

static char	*full_join_arg(int nbA, char **val)
{
	char		*tmp1;
	char		*tmp2;
	int			i;

	tmp2 = malloc(sizeof(char));
	if (!tmp2)
		return (NULL);
	i = 1;
	while (i < nbA)
	{
		if (!val[i][0] || is_justspace(val[i]))
		{
			ft_putstr("Error\n", 2);
			free(tmp2);
			return (NULL);
		}
		tmp1 = ft_strjoin(tmp2, val[i]);
		free(tmp2);
		tmp2 = ft_strjoin(tmp1, " ");
		free(tmp1);
		i++;
	}
	return (tmp2);
}

long int	*ft_load(int nbA, char **val, size_t *nbV)
{
	long int	*res;
	char		*join_arg;

	if (nbA < 2)
		return (NULL);
	join_arg = full_join_arg(nbA, val);
	if (!join_arg)
		return (NULL);
	res = ft_split_atoi(join_arg, ' ', nbV);
	if (!res || *nbV < 2 || ft_issorted(*nbV, res) || find_zero(res, *nbV) > 1)
	{
		if (res && find_zero(res, *nbV) > 1)
			ft_putstr("Error\n", 2);
		free(res);
		res = NULL;
	}
	return (free(join_arg), res);
}



t_list	**ft_fill_list(size_t nbv, long int *val, t_list **l)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	while (i < nbv)
	{
		tmp = ft_lstnew(ft_index(i, val, nbv));
		if (!tmp)
		{
			ft_lstclear(l);
			return (l);
		}
		ft_lstadd_back(l, tmp);
		i++;
	}
	return (l);
}
