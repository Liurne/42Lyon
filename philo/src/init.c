/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:33:03 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 16:33:39 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void destroy_philos(t_data *data, int nb_forks)
{
	while (nb_forks != -1)
	{
		pthread_mutex_destroy(&data->philos[nb_forks].m_l_fork);
		nb_forks--;
	}
	free(data->philos);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->start);
}


int	new_philo(t_data *data, t_philo *philo, int id)
{
	ft_bzero(philo, sizeof(t_philo));
	philo->id = id + 1;
	philo->shared = data;
	if (pthread_mutex_init((&(philo->m_l_fork)), NULL))
			return(0);
	philo->m_r_fork = &(data->philos[(id + 1) % data->nb_philo].m_l_fork);
	philo->r_fork = &(data->philos[(id + 1) % data->nb_philo].l_fork);
	if (data->nb_philo == 1)
		philo->m_r_fork = NULL;
	return	(1);
}

int	init_philos(t_data *data)
{
	int	i;
	data->philos = (t_philo *)malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philos)
		return (error_msg(2));
	i = -1;
	while (++i < data->nb_philo)
		if(!new_philo(data, &(data->philos[i]), i))
			return(destroy_philos(data, i), error_msg(3));
	return (1);
}
