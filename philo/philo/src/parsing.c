/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:23:09 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/13 14:58:17 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_arg(int ac, char **av, t_data *table)
{
	if (ac < 5 || ac > 6)
		return (error_manager(1, table));
	table->nb_philo = ft_atoi(av[1]);
	table->t_death = ft_atoi(av[2]);
	table->t_eat = ft_atoi(av[3]);
	table->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->nb_meal = ft_atoi(av[5]);
	if (table->nb_philo <= 0 || table->t_death <= 0 || table->t_eat <= 0
		|| table->t_sleep <= 0 || (ac == 6 && table->nb_meal <= 0))
		return (error_manager(2, table));
	if (table->t_death < 60 || table->t_eat < 60 || table->t_sleep < 60)
		printf("Warning : The args are too low %s\n",
			"(the subject told you to not test that !)");
	if (table->nb_philo > 200)
		printf("Warning : The number of philos is too high%s\n",
			"(the subject told you to not test that !)");
	return (0);
}
