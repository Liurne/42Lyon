/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:04:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/09 14:31:47 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	close_philo(t_data *table)
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
		if (table->philos[i].m_fork_left)
			pthread_mutex_destroy(&(table->philos[i].m_fork_left));
	}
	pthread_mutex_destroy(&(table->m_write));
	free(table->philos);
	return ()
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
	if (id_error == 5)
		printf("Error : Couldn't init the muttex.\n");
	close_philo(table);
	if (id_error != 0)
		exit (1);
	return (0);
}