/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:04:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/07 16:41:21 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_manager(int id_error)
{
	if (id_error == 1)
		printf("Error : Invalid number of arguments.\n");
	if (id_error == 2)
		printf("Error : Invalid argument.\n");
	if (id_error == 3)
		printf("Error : Couldn't init the thread.\n");
	if (id_error == 4)
		printf("Error : Malloc failed\n");
	return (1);
}