/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:06:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/07 17:13:52 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_data *data)
{
	data->table = (t_philo *)malloc(data ->nb_philo * sizeof(t_philo));
	if (!data->table)
		return (error_manager(4));
	if (pthread_create(&data->table[0].thread, NULL, (void *) thread_tester, "je marche !!") != 0)
		printf("Couldn't bring forth the thread\n");
	pthread_join(data->table[0].thread, NULL);
	return (0);
}