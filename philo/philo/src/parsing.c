/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:23:09 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/07 15:39:07 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_arg(int ac, char **av, t_data *philo)
{
	if (ac < 5 || ac > 6)
		return (error_manager(1));
	philo->nb_philo = ft_atoi(av[1]);
	philo->t_death = ft_atoi(av[2]);
	philo->t_eat = ft_atoi(av[3]);
	philo->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_meal = ft_atoi(av[5]);
	if (philo->nb_philo <= 0 || philo->t_death <= 0 || philo->t_eat <= 0
		|| philo->t_sleep <= 0 || (ac == 6 && philo->nb_meal <= 0))
		return (error_manager(2));
	if (philo->t_death < 60 || philo->t_eat < 60 || philo->t_sleep < 60)
		printf("Warning : The args are too low %s\n",
			"(the subject told you to not test that !)");
	if (philo->nb_philo > 200)
		printf("Warning : The number of philos is too high%s\n",
			"(the subject told you to not test that !)");
	return (0);
}
