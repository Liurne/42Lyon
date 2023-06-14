/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:51:44 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/14 18:06:06 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_say(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (philo->shared->is_dead)
	{
		pthread_mutex_unlock(&(philo->shared->whistleblower));
		return (1);
	}
	if (philo->lifespan < get_time())
		philo->shared->is_dead = 1;
	printf("%ld %d %s\n", (get_time() - philo->shared->t_start), philo->id,
		action);
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	return (0);
}

int	is_alivnt(t_philo *philo)
{
	if (philo->lifespan < get_time())
	{
		philo->alive = 0;
		philo_say(philo, DIE);
		return (1);
	}
	return (0);
}

int	routine(t_philo *philo)
{
	int	rvalue;

	rvalue = 0;
	philo->alive = 1;
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	philo->lifespan = get_time() + philo->shared->t_death;
	if (!(philo->id % 2))
		usleep(1000);
	while (philo->alive)
	{
		if (want_to_eat(philo))
			return (1);
		rvalue = want_to_sleep(philo);
		if (rvalue == 1)
			return (1);
		if (rvalue == -1)
			return (0);
	}
	return (0);
}