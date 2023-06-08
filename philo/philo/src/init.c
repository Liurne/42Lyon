/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 01:06:21 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/08 12:52:14 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	l;
	size_t	i;

	l = 0;
	while (s[l])
		l++;
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (s[++i] && l != 0)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

int	launch_one_philo(t_data *data, int id_philo)
{
	data->table[id_philo].id = id_philo;
	data->table[id_philo].shared = data;
	data->table[id_philo].msg = ft_strdup("je marche !!\0");
}

int	init_philos(t_data *data)
{
	int	i;

	data->table = (t_philo *)malloc(data->nb_philo * sizeof(t_philo));
	if (!data->table)
		return (error_manager(4));
	i = 0;
	pthread_mutex_init(&(data->m_write), NULL);
	pthread_mutex_lock(&(data->m_write));
	while (i < data->nb_philo)
	{
		
		if (pthread_create(&data->table[i].thread, NULL, (void *) thread_tester,
				&(data->table[i])) != 0)
			printf("Couldn't bring forth the thread\n");
		i++;
	}
	pthread_mutex_unlock(&(data->m_write));
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->table[i].thread, NULL);
		free(data->table[i].msg);
		printf("Thread nb %d killed\n", i);
		i++;
	}
	pthread_mutex_destroy(&(data->m_write));
	free(data->table);
	return (0);
}
