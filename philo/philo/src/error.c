/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:04:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/13 17:52:21 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	close_philo(t_data *table, int id_error)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		if (table->philos[i].thread)
		{
			pthread_join(table->philos[i].thread, NULL);
			printf("Thread nb %d killed\n", table->philos[i].id);
		}
		if (table->philos[i].id)
			pthread_mutex_destroy(&(table->philos[i].m_fork_left));
	}
	if (id_error != 6 || id_error != 7)
		pthread_mutex_destroy(&(table->whistleblower));
	if (id_error != 6)
		pthread_mutex_destroy(&(table->launcher));
	free(table->philos);
	return (0);
}

int	error_manager(int id_error, t_data *table)
{
	if (id_error == 1)
		printf("Error : Invalid number of arguments.\n");
	if (id_error == 2)
		printf("Error : Invalid argument.\n");
	if (id_error == 3)
		printf("Error : Malloc failed\n");
	if (id_error == 4)
		printf("Error : Couldn't init the thread.\n");
	if (id_error == 5 || id_error == 6 || id_error == 7)
		printf("Error : Couldn't init the muttex.\n");
	close_philo(table, id_error);
	if (id_error != 0)
		exit (1);
	return (0);
}

int	philo_say(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (philo->shared->is_dead)
	{
		pthread_mutex_unlock(&(philo->shared->whistleblower));
		return (1);
	}
	printf("%ld %d %s\n", (get_time() - philo->shared->t_start), philo->id,
		action);
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	return (0);
}