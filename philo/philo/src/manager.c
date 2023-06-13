/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:25:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/13 17:53:52 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_tester(t_philo *test)
{
	pthread_mutex_lock(&(test->shared->launcher));
	pthread_mutex_unlock(&(test->shared->launcher));
	dprintf(2, "Bonjour je suis thread numero %d.\n", test->id);
	dprintf(2, "On m'a dit de vous communiquer cette information :\n");
	dprintf(2, "Elle est trop bien la voiture de Thea\n");
	dprintf(2, "Ma tache etant finis je vais cesser d'exister...\n");
	return (0);
}

int	routine(t_philo *philo)
{
	int	alive;

	alive = 1;
	pthread_mutex_lock(&(philo->shared->launcher));
	philo->last_meal = get_time() + philo->shared->t_death;
	pthread_mutex_unlock(&(philo->shared->launcher));
	if (philo->id % 2)
		usleep(1000);
	printf("ok\n");
	philo_say(philo, THINK);
	while (alive)
	{
		if (philo->last_meal < get_time())
		{
			alive = 0;
			continue;
		}
	}
	return (0);
}
