/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/01/10 15:53:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_load(int nbA, char **val, size_t *nbV)
{
	long int	*res;
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
	res = ft_split_atoi(tmp, ' ', nbV);
	free(tmp);
	return (res);
}

t_list	**ft_fill_tab(int nbA, char **val);

int	main(int ac, char **av)
{
	long int	*tmp;	
	size_t		nb_val;
	size_t		i;

	tmp = ft_load(ac, av, &nb_val);
	if (!tmp)
		return (1);
	printf("%zu\n", ft_strlen("-2147483648"));
	i = 0;
	while (i < nb_val)
	{
		printf("test :%ld\n",tmp[i]);
		i++;
	}
	/*if (!verif_val(nb_val, tmp))
	{
		ft_putstr("Error\n");
		ft_free(tmp, nb_val);
		return (0);
	}*/
	//ft_free(tmp, nb_val);
	free(tmp);
	return (0);
}
