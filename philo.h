/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 18:21:54 by jschneid         ###   ########.fr       */
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
	pthread_mutex_t	print_lock;
	pthread_mutex_t	fed_up_lock;
	pthread_mutex_t	wait_lock;
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

//---------------Initialize---------------//
int				init_forks(t_info *info);
t_info			*init_info(int argc, char **argv);
void			init_philo(t_info *info, t_philo *philo, int i);
//----------------Parsing----------------//
int				input_check(int argc, char **argv);
//----------------Threads----------------//
int				create_threads(t_info *info);
//--------------Routine_00--------------//
void			*routine(void *v);
void			philo_schedule(t_philo *philo);
int				take_left_fork(t_philo *philo);
int				take_right_fork(t_philo *philo);
int				start_eating(t_philo *philo);
//--------------Routine_01--------------//
int				start_sleeping(t_philo *philo);
int				start_thinking(t_philo *philo);
int				put_down_forks(t_philo *philo);
//-----------------Utils-----------------//
int				ft_atoi(const char *nptr);
unsigned long	time_ms(void);
void			my_sleep(unsigned long time, int nbr_philos);
void			print_message(char c, t_philo *philo);

#endif
