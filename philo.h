/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 13:31:07 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_info {
	int				nbr_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				philos_init;
	int				wait_flag;
	int				fed_up;
	int				die;
	int				created_threads;
	unsigned long	time_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*fed_up_lock;
	pthread_mutex_t	*wait_lock;
}	t_info;

typedef struct s_philo {
	pthread_t		thread;
	int				philo_id;
	int				meal_counter;
	unsigned long	last_meal;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_info			*info;
}	t_philo;

//---------------initialize---------------//
int		init_forks(t_info *info);
t_info	*init_info(int argc, char **argv);
void	init_philo(t_info *info, t_philo *philo, int i);

//----------------parsing----------------//
int		input_check(int argc, char **argv);

//----------------threads----------------//
int		create_threads(t_info *info);

//-----------------utils-----------------//
int		ft_atoi(const char *nptr);
int		time_ms(void);

//----------------routine----------------//
void	*routine(void *v);

#endif
