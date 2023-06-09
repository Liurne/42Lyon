/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:06:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/09 15:28:54 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	launch_one_philo(t_data *table, int id_ph)
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
	if (pthread_create(&table->philos[id_ph].thread, NULL,
			(void *)thread_tester, &(table->philos[id_ph])) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *table)
{
	int	i;

	table->philos = (t_philo *)ft_calloc(table->nb_philo, sizeof(t_philo));
	if (!table->philos)
		return (error_manager(4));
	i = -1;
	if (pthread_mutex_init(&(table->m_write), NULL) != 0)
		return (error_manager(4))
	pthread_mutex_lock(&(table->m_write));
	while (++i < table->nb_philo)
	{
		if (launch_one_philo(table, i))
			return (error_manager());
	}
	pthread_mutex_unlock(&(table->m_write));
	return (0);
}
