/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:03:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/08 12:50:20 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/philo.h"

int	main(int ac, char **av)
{
	t_data	philo;

	ft_bzero(&philo, sizeof(t_data));
	get_arg(ac, av, &philo);
	init_philos(&philo);
	return (0);
}