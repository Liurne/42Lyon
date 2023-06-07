/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:25:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/07 17:11:55 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thread_tester(char *test)
{
	dprintf(2, "Bonjour je suis un thread.\n");
	dprintf(2, "On m'a dit de vous communiquer cette information :\n");
	dprintf(2, "%s\n", test);
	dprintf(2, "Ma tache etant finis je vais cesser d'exister...\n");
	return (0);
}