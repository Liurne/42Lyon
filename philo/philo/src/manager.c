/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:25:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/14 11:22:52 by jcoquard         ###   ########.fr       */
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

int	is_died(t_philo *philo)
{
	pthread_mutex_lock(&(philo->shared->whistleblower));
	if (philo->last_meal < get_time())
	{
		philo->alive = 0;
		philo_say(philo, DIE);
		philo->shared->is_dead = 1;
		exit(0);
	}
	pthread_mutex_unlock(&(philo->shared->whistleblower));
	return (0);
}

int	try_to_take_fork(t_philo *philo, pthread_mutex_t *m_fork, int *fork)
{
	is_died(philo);
	pthread_mutex_lock(m_fork);
	if (!*fork)
	{
		*fork = philo->id;
		return (1);
	}
	pthread_mutex_unlock(m_fork);
	return (0);
}

int put_back_fork(t_philo *philo, pthread_mutex_t *m_fork, int *fork)
{
	if (!m_fork)
	{
		pthread_mutex_lock(m_fork);
		if (*fork == philo->id)
		{
			*fork = 0;
			return (1);
		}
		pthread_mutex_unlock(m_fork);
	}
	return (0);
}

int	do_stuff(t_philo *philo, int duration)
{
	duration += get_time();
	while (duration > get_time())
		i++;
}

int	want_to_eat(t_philo *philo)
{
	int	has_eaten;

	has_eaten = 0;
	while (philo->alive && has_eaten < 2)
	{
		while (!has_eaten)
		{
			has_eaten += try_to_take_fork(philo, &(philo->m_fork_left),
					&(philo->fork_left));
		}
		while (has_eaten < 2)
		{
			has_eaten += try_to_take_fork(philo, philo->m_fork_right,
					philo->fork_right);
		}
		philo_say(philo, EAT);
		put_back_fork(philo, &(philo->m_fork_left), &(philo->fork_left));
		put_back_fork(philo, philo->fork_right, philo->fork_right);
		
		
	}
	return (0);
}

int	routine(t_philo *philo)
{

	philo->alive = 1;
	pthread_mutex_lock(&(philo->shared->launcher));
	philo->last_meal = get_time() + philo->shared->t_death;
	pthread_mutex_unlock(&(philo->shared->launcher));
	if (philo->id % 2)
		usleep(1000);
	printf("ok\n");
	philo_say(philo, THINK);
	while (philo->alive)
	{
		
	}
	return (0);
}
