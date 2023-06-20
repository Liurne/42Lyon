/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:49:30 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/20 15:42:43 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	do_stuff(t_philo *philo, int duration)
{
	duration += get_time();
	while (duration > get_time())
	{
		if (is_alivnt(philo))
			return (1);
		usleep(philo->shared->nb_philo * 10);
	}
	return (0);
}

static int	try_to_take_fork(t_philo *philo, pthread_mutex_t *m_fork, int *fork)
{
	if (is_alivnt(philo))
		return (-1);
	pthread_mutex_lock(m_fork);
	if (m_fork && !(*fork))
	{
		*(fork) = philo->id;
		if (philo_say(philo, FORK))
			return (pthread_mutex_unlock(m_fork), -1);
		return (pthread_mutex_unlock(m_fork), 1);
	}
	pthread_mutex_unlock(m_fork);
	return (0);
}

static void	put_back_fork(t_philo *philo, pthread_mutex_t *m_fork, int *fork)
{
	if (m_fork)
	{
		pthread_mutex_lock(m_fork);
		if (*(fork) == philo->id)
			*(fork) = 0;
		pthread_mutex_unlock(m_fork);
	}
}

int	want_to_sleep(t_philo *philo)
{
	if (philo_say(philo, SLEEP))
		return (1);
	put_back_fork(philo, &(philo->m_fork_left), &(philo->fork_left));
	put_back_fork(philo, philo->m_fork_right, philo->fork_right);
	if (do_stuff(philo, philo->shared->t_sleep))
		return (1);
	return (0);
}

int	want_to_eat(t_philo *philo)
{
	int	fork1;
	int	fork2;

	philo_say(philo, THINK);
	fork1 = 0;
	fork2 = 0;
	while (!fork1 || !fork2)
	{
		if (!fork1)
			fork1 += try_to_take_fork(philo, &(philo->m_fork_left),
					&(philo->fork_left));
		if (!fork2)
			fork2 += try_to_take_fork(philo, philo->m_fork_right,
					philo->fork_right);
		if (fork1 == -1 || fork2 == -1)
			return (1);
		usleep(philo->shared->nb_philo * 10);
	}
	if (philo_say(philo, EAT))
		return (1);
	philo->lifespan = get_time() + philo->shared->t_death;
	if (do_stuff(philo, philo->shared->t_eat))
		return (1);
	return (0);
}
