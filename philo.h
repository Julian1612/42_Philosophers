/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:03:30 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/17 16:10:47 by jschneid         ###   ########.fr       */
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
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	*forks_arr;
}	t_philo;

typedef struct s_info {
	int		philo_id;
	int		fork_right;
	int		fork_left;
	int		last_time_eaten;
	t_philo	*philo;
}	t_info;


int		ft_atoi(const char *nptr);
int		*initialize_forks(t_philo *var);
int		input_check(int argc, char *argv[]);
void	initialize_variable(t_philo *var, int argc, char *argv[]);
void	initialize_struct(t_info *var);
void	*philo_schedule(void *v);

#endif
