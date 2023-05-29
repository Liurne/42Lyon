/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:27:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 16:52:15 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void end_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		pthread_join(data->philos[i].thread_id, NULL);
	destroy_philos(data, data->nb_philo);
}

void	*philosophing(void *ptr)
{
	t_philo	*philo;

	philo = ptr;
	pthread_mutex_lock(&philo->data->start);
	philo->tl_meal = philo->data->t_start;
	pthread_mutex_unlock(&philo->data->start);
	if (philo->tl_meal == -1)
		return (NULL);
	p_print(philo, "is thinking");
	if (philo->id % 2 == 0)
		p_pause(philo, (philo->data->t_eat * 0.9));
	while (is_end(philo->data) == 0)
	{
		if (p_eat(philo))
			break ;
		p_print(philo, "is sleeping");
		if (p_pause(philo, philo->data->t_sleep))
			break ;
		p_print(philo, "is thinking");
	}
	philo->nb_meal = -1;
	return (NULL);
}

int start_philos(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->start);
	while(++i < data->nb_philo)
		if (pthread_create(&(data->philos[i].thread_id), NULL, &philosophing, &(data->philos[i])))
		{
			error_msg(4);
			break;
		}
	data->t_start = get_time();
	pthread_mutex_unlock(&(data->start));
	if (i != data->nb_philo)
		return (data->nb_philo = i, 0);
	return (1);
			
}