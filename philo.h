/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/28 12:55:18 by jschneid         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_info {
	int				nbr_philos;			//	Number of Philosophers on the table
	int				time_die;			//	Time a philosopher must die when he haven't ate
	int				time_eat;			//	Zeit wie lange gegessen werden soll
	int				time_sleep;			//	Zeit wie lange geschlafen werden soll
	int				max_meals;			//	Anzahl wie viele Mahlzeiten die Philos essen sollen
	int				philos_init;		//	Gives the signal that all philos are initzialied (when > 0)
	int				wait_flag;			//	Gives the Sig
	int				fed_up;				//	flag wenn ein philo aufgegessen hat
	int				die;				//	flag for all philo to die instantly
	int				created_threads;	//	-
	unsigned long	time_start;			//	Start time of all threads
	pthread_mutex_t	*forks;				//	Array wich displays the forks on the table
	pthread_mutex_t	print_lock;			//	Print lock that only one philo can print
	pthread_mutex_t	fed_up_lock;		//
	pthread_mutex_t	wait_lock;			//
}	t_info;

typedef struct s_philo {
	int				philo_id;			//	ID of the Philo
	int				meal_counter;		//	Eaten meals form philo
	unsigned long	meal_timer;		 	//	Time of the last meal of philo
	pthread_t		thread;				//	idk
	pthread_mutex_t	*fork_right;		//	The fork on the right side of the philo
	pthread_mutex_t	*fork_left;			//	The fork on the left side of the philo
	t_info			*info;				//	Link to the other info struct with the general informations
}	t_philo;

//---------------Initialize---------------//
int				init_forks(t_info *info);
t_info			*init_info(int argc, char **argv);
void			init_philo(t_info *info, t_philo *philo, int i);
//-------------join_destroy--------------//
void			destroy_threads(t_philo *philo);
void			join_threads(t_philo *philo);
void			free_structs(t_philo *philo, t_info *info);
//----------------Parsing----------------//
int				input_check(int argc, char **argv);
//----------------Threads----------------//
int				create_threads(t_info *info, t_philo *philo);
//--------------Routine_00--------------//
void			*routine(void *v);
void			philo_schedule(t_philo *philo);
void			philo_eat(t_philo *philo);
//--------------Routine_01--------------//
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
//--------------Thread_check--------------//
void			thread_checker(t_philo *philo);
//-----------------Utils-----------------//
int				ft_atoi(const char *nptr);
unsigned long	time_ms(void);
void			my_usleep(unsigned long time, int nbr_philo);
void			print_message(char c, t_philo *philo);

#endif
