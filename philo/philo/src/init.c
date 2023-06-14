/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:06:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/14 16:06:29 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	launch_one_philo(t_data *table, int id_ph, int ac)
{
	table->philos[id_ph].shared = table;
	if (pthread_mutex_init(&(table->philos[id_ph].m_fork_left), NULL) != 0)
		return (1);
	else
		table->philos[id_ph].id = id_ph + 1;
	if (id_ph == table->nb_philo - 1 && table->nb_philo != -1)
	{
		table->philos[id_ph].m_fork_right = &(table->philos[0].m_fork_left);
		table->philos[id_ph].fork_right = &(table->philos[0].fork_left);
	}
	else if (table->nb_philo != -1)
	{
		table->philos[id_ph].m_fork_right
			= &(table->philos[id_ph + 1].m_fork_left);
		table->philos[id_ph].fork_right = &(table->philos[id_ph + 1].fork_left);
	}
	if (ac == 6)
		table->philos[id_ph].nb_meal = table->nb_meal;
	else
		table->philos[id_ph].nb_meal = -1;
	if (pthread_create(&table->philos[id_ph].thread, NULL,
			(void *)routine, &(table->philos[id_ph])) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *table, int ac)
{
	int	i;

	table->philos = (t_philo *)ft_calloc(table->nb_philo, sizeof(t_philo));
	if (!table->philos)
		return (error_manager(3, table));
	i = -1;
	if (pthread_mutex_init(&(table->launcher), NULL) != 0)
		return (error_manager(6, table));
	if (pthread_mutex_init(&(table->whistleblower), NULL) != 0)
		return (error_manager(7, table));
	pthread_mutex_lock(&(table->launcher));
	while (++i < table->nb_philo)
	{
		if (launch_one_philo(table, i, ac))
			return (error_manager(5, table));
	}
	table->t_start = get_time();
	pthread_mutex_unlock(&(table->launcher));
	return (0);
}

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
