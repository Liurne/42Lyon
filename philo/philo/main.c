/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:03:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/14 16:06:49 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/philo.h"

int	main(int ac, char **av)
{
	t_data	table;

	ft_bzero(&table, sizeof(t_data));
	get_arg(ac, av, &table);
	init_philos(&table, ac);
	error_manager(0, &table);
	return (0);
}
