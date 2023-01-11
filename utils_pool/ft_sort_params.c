/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:22:24 by jcoquard          #+#    #+#             */
/*   Updated: 2022/07/17 20:06:34 by jcoquard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

void	ft_compare(char **argv, int j, int *p)
{
	char	*tmp;

	if (ft_strcmp(argv[*p], argv[j]) == 1)
	{
		tmp = argv[*p];
		argv[*p] = argv[j];
		argv[j] = tmp;
		*p = j;
	}
	else
	{
		*p = j;
	}
}

void	ft_sort_int_tab(char **argv, int size)
{
	int	i;
	int	j;
	int	p;

	i = 1;
	while (i < size)
	{	
		p = 1;
		j = 1;
		while (j < size)
		{
			ft_compare(argv, j, &p);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{	
	int	i;
	int	j;

	ft_sort_int_tab(argv, argc);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
