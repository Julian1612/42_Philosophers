/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 13:56:07 by jschneid         ###   ########.fr       */
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

typedef struct s_philo {
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				*forks_arr;
	int				philos_init;
	int				time;
	pthread_mutex_t	*arr_mutex_fork;
}	t_philo;

typedef struct s_info {
	int				philo_id;
	int				last_time_eaten;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
	t_philo			*philo;
}	t_info;

int		ft_atoi(const char *nptr);
int		initialize_forks(t_philo *var);
int		input_check(int argc, char *argv[]);
void	initialize_variable(t_philo *var, int argc, char *argv[]);
void	initialize_struct(t_info *arr, t_philo *var, int i);
void	*philo_schedule(void *v);
void	philo_routine(t_info var);
int		take_left_fork(t_info var);
int		take_right_fork(t_info var);
int		start_eating(t_info var);
int		start_sleeping(t_info var);
int		start_thinking(t_info var);
int		put_down_forks(t_info var);

#endif
