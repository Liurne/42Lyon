/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:07:29 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/07 01:17:50 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//un thread par philosophe
//penser au cas 1 philosophe donc 1 fourchette
//fourchette et pointeur sur fourchette par philo
//faire attention à l'ordre des verrou sur mutex ?
//empecher d'ecrire des messages en meme temps !!
//pthread_mutex_lock() pthread_mutex_unlock(); au debut et a la fin de la fct ou quand on consulte une variable !!
//pthread_mutex_destroy(); pthread_mutex_init(&table->m_end, NULL);
//verifier à chaque action si philo mort !!
//id du philo dans la fork utilisé à retirer quand plus utilisé
//pthread_create(); pour creer
//pthread_join(); pour finir
//penser a bien attendre tout thread et detruire tout les mutexs !!
//pointeur sur data pour les temps et mort pointeur sur philo pour les ids !!


typedef struct s_data
{
	int				nb_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				t_start;
	int				nb_meal;
	int				is_dead;
	pthread_mutex_t	m_write;
	t_philo			*table;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	m_fork_left;
	pthread_mutex_t	*m_fork_right;
	int				fork_left;
	int				*fork_right;
	int				last_meal;
	int				nb_meal;
	t_data			*shared;
}	t_philo;

/* -----utils----- */
long int	get_time(void);
int	ft_atoi(const char *str);

/* -----parsing----- */

/* -----init----- */

/* -----manager----- */

/* -----error----- */

#endif