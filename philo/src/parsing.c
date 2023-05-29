/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:45:51 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 14:44:49 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	error_msg(int val_err)
{
	if (val_err == 0)
		printf("Error : invalid number of arguments\n");
	if (val_err == 1)
		printf("Error : negative values are not allowed\n");
	if (val_err == 2)
		printf("Error : malloc failed\n");
	if (val_err == 3)
		printf("Error : mutex failed\n");
	return (0);
}

int	check_args(t_data *data)
{
	if (data->nb_philo < 0)
		return(error_msg(1));
	if (data->t_death < 0)
		return(error_msg(1));
	if (data->t_eat < 0)
		return(error_msg(1));
	if (data->t_sleep < 0)
		return(error_msg(1));
	if (data->nb_meal < 0)
		return(error_msg(1));
	return (1);	
}

int	parsing(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac  != 6)
		return (error_msg(0));
	ft_bzero(data, sizeof(t_data));
	if(ac == 6)
		data->nb_meal = ft_atoi(av[5]);
	data->nb_philo = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (pthread_mutex_init(&data->death, NULL))
		return (error_msg(3));
	if (pthread_mutex_init(&data->start, NULL))
		return (pthread_mutex_destroy(&data->death), error_msg(3));
	return (check_args(data));
}