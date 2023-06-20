/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:51:44 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/20 16:45:51 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_say(t_philo *philo, char *action)
{
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (philo->shared->is_dead)
		return (pthread_mutex_unlock(&(philo->shared->whistleblower)), 1);
	if (philo->lifespan < get_time())
		philo->shared->is_dead = 1;
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	printf("%ld %d %s\n", (get_time() - philo->shared->t_start), philo->id,
		action);
	return (0);
}

int	is_alivnt(t_philo *philo)
{
	if (philo->lifespan < get_time() || philo->shared->is_dead)
	{
		philo->alive = 0;
		philo_say(philo, DIE);
		return (1);
	}
	return (0);
}

int	is_belly_full(t_philo *philo)
{
	if (philo->nb_meal != -1)
	{
		philo->nb_meal--;
		pthread_mutex_lock(&(philo->shared->whistleblower));
		if (!philo->nb_meal)
			philo->shared->belly_full++;
		if (philo->shared->belly_full == philo->shared->nb_philo)
			return (pthread_mutex_unlock(&(philo->shared->whistleblower)), 1);
		pthread_mutex_unlock(&(philo->shared->whistleblower));
	}
	return (0);
}

int	routine(t_philo *philo)
{
	philo->alive = 1;
	pthread_mutex_lock(&(philo->shared->launcher));
	pthread_mutex_unlock(&(philo->shared->launcher));
	philo->lifespan = get_time() + philo->shared->t_death;
	if (!(philo->id % 2))
		usleep(10000);
	while (philo->alive)
	{
		if (want_to_eat(philo))
			return (1);
		if (want_to_sleep(philo))
			return (1);
		if (is_belly_full(philo))
			return (0);
		//if (get_time() < philo->shared.t_start)
	}
	return (0);
}
