/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:30:47 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 17:05:02 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	p_pause(t_philo *philo, long int duration)
{
	long int	end_time;

	end_time = get_time() + duration;
	if (end_time == -1)
		return (-1);
	while (get_time() < end_time)
	{
		if (is_end(philo->data) || p_died(philo))
			return (1);
		usleep(philo->data->time_pause * 2);
	}
	return (0);
}

void	p_take_fork(pthread_mutex_t *m_fork, t_philo *p, int *fork, int *wit)
{
	pthread_mutex_lock(m_fork);
	if (*fork == 0)
	{
		*fork = p->id;
		--(*wit);
		p_print(p, "has taken a fork");
	}
	pthread_mutex_unlock(m_fork);
}

int	p_try_fork(t_philo *philo)
{
	pthread_mutex_t	*m_fork[2];
	int				wit;

	m_fork[0] = &philo->m_l_fork;
	m_fork[1] = philo->m_r_fork;
	wit = 2;
	while (wit)
	{
		p_take_fork(m_fork[0], philo, &philo->l_fork, &wit);
		if (m_fork[1])
			p_take_fork(m_fork[1], philo, philo->r_fork, &wit);
		if (p_died(philo) || is_end(philo->data))
			return (1);
		usleep(philo->data->time_pause);
	}
	return (0);
}

int	p_give_back_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_l_fork);
	philo->l_fork = 0;
	pthread_mutex_unlock(&philo->m_l_fork);
	pthread_mutex_lock(philo->m_r_fork);
	*philo->r_fork = 0;
	pthread_mutex_unlock(philo->m_r_fork);
	return (0);
}

int	p_eat(t_philo *philo)
{
	if (p_try_fork(philo))
		return (1);
	philo->tl_meal = get_time();
	p_print(philo, "is eating");
	++philo->nb_meal;
	if (philo->nb_meal == philo->data->nb_meal)
	{
		pthread_mutex_lock(&philo->data->m_end);
		++philo->data->dead;
		pthread_mutex_unlock(&philo->data->m_end);
	}
	if (p_pause(philo, philo->data->time_eat))
	{
		p_give_back_fork(philo);
		return (1);
	}
	p_give_back_fork(philo);
	if (is_end(philo->data))
		return (1);
	return (0);
}