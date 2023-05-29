/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquard <jcoquard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:26:42 by jcoquard          #+#    #+#             */
/*   Updated: 2023/05/09 17:03:33 by jcoquard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo {
	pthread_t		thread_id;
	int				id;
	int				nb_meal;
	int				tl_meal;
	pthread_mutex_t	m_l_fork;
	pthread_mutex_t	*m_r_fork;
	int				l_fork;
	int				*r_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				nb_meal;
	int				t_start;
	int				d_philo;
	t_philo			*philos;
	pthread_mutex_t	m_start;
	pthread_mutex_t	m_end;
}	t_data;

/* -----utils----- */
void		ft_bzero(void *s, long int n);
int			ft_atoi(const char *str);
long int	get_time();

/* -----parsing----- */
int			error_msg(int val_err);
int			parsing(t_data *philo, int ac, char **av);

/* -----init----- */
void		destroy_philos(t_data *data, int nb_forks);
int			init_philos(t_data *data);

/* -----thread----- */
void		end_philos(t_data *data);
int			start_philos(t_data *data);

#endif