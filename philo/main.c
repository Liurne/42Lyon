/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:26:39 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 16:46:59 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/philo.h"

int	main(int ac, char **av)
{
	t_data	philo;
	(void)ac;
	(void)av;
	parsing(&philo, ac, av);
	if(!init_philos(&philo))
		return(1);
	start_philos(&philo);
	end_philos(&philo);
	printf("time of the day:%ld\n", get_time());
	return (0);
}