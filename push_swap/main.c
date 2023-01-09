/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/09 16:48:32 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_load(int nbA, char **val, size_t *nbV)
{
	char	**res;
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	i = 1;
	while (i < nbA)
	{
		tmp = ft_strjoin(tmp, val[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	res = ft_split(tmp, ' ', nbV);
	free(tmp);
	return (res);
}

t_value	**ft_fill_tab(int nbA, char **val, )

int	main(int ac, char **av)
{
	char		**tmp;
	size_t		nb_val;
	int			i;

	tmp = ft_load(ac, av, &nb_val);
	if (!tmp)
		return (1);
	printf("%zu\n", ft_strlen("-2147483648"));
	while (i < nb_val)
	{
		ft_putstr(tmp[i]);
		ft_putstr("\n");
		i++;
	}
	if (!verif_val(nb_val, tmp))
	{
		ft_putstr("Error\n");
		ft_free(tmp, nb_val);
		return (0);
	}
	ft_free(tmp, nb_val);
	return (0);
}
