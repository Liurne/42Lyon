/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:07:29 by jcoquard          #+#    #+#             */
/*   Updated: 2023/06/14 16:19:08 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//Yes - un thread par philosophe
//Yes - penser au cas 1 philosophe donc 1 fourchette
//Yes - fourchette et pointeur sur fourchette par philo
//?? - faire attention à l'ordre des verrou sur mutex ?
//Yes - empecher d'ecrire des messages en meme temps !!
//Yes - pthread_mutex_lock() pthread_mutex_unlock(); au debut et a la fin de la 
//fct ou quand on consulte une variable !!
//Yes - pthread_mutex_destroy(); pthread_mutex_init(&table->m_end, NULL);
//Yes - verifier à chaque action si philo mort !!
//Yes - id du philo dans la fork utilisé à retirer quand plus utilisé
//Yes - pthread_create(); pour creer
//Yes - pthread_join(); pour finir
//Yes - penser a bien attendre tout thread et detruire tout les mutexs !!
//Yes - pointeur sur data pour les temps et mort pointeur sur philo pour 
//les ids !!
//Yes - creer un decallage entre chaque philo !!
//No - verif bug timer et proteger sur grosse duree
//No - optimiser
//No - verifier que les actions soit bien fini quand on lance la suivante

# define THINK "is thinking"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define DIE "died"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	long int		t_start;
	int				nb_meal;
	int				is_dead;
	pthread_mutex_t	launcher;
	pthread_mutex_t	whistleblower;
	t_philo			*philos;
}	t_data;

struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	m_fork_left;
	pthread_mutex_t	*m_fork_right;
	int				fork_left;
	int				*fork_right;
	long int		lifespan;
	int				nb_meal;
	int				alive;
	t_data			*shared;
};

/* -----utils----- */
long int	get_time(void);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);

/* -----parsing----- */
int			get_arg(int ac, char **av, t_data *philo);
int			init_philos(t_data *data, int ac);

/* -----routine----- */
int			routine(t_philo *philo);
int		is_alivnt(t_philo *philo);
int		philo_say(t_philo *philo, char *action);


/* -----action----- */
int		want_to_eat(t_philo *philo);
int		want_to_sleep(t_philo *philo);

/* -----error----- */
int			error_manager(int id_error, t_data *table);

#endif