/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 00:25:25 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/09 14:06:07 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    thread_tester(t_philo *test)
{
    pthread_mutex_lock(&(test->shared->m_write));
    pthread_mutex_unlock(&(test->shared->m_write));
    dprintf(2, "Bonjour je suis thread numero %d.\n", test->id);
    dprintf(2, "On m'a dit de vous communiquer cette information :\n");
    dprintf(2, "Elle est trop bien la voiture de Thea\n");
    dprintf(2, "Ma tache etant finis je vais cesser d'exister...\n");
    return (0);
} 