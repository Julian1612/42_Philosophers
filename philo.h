/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/21 11:07:14 by jschneid         ###   ########.fr       */
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
	unsigned long	time_last_meal;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_info			*philo;
}	t_philo;

int	ft_atoi(const char *nptr);
int	input_check(int argc, char **argv);

#endif
