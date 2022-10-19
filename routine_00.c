/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:47:31 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 13:39:57 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_schedule(void *v)
{
	t_info			var;
	struct timeval	current_time;

	var = *(t_info *)v;
	gettimeofday(&current_time, NULL);
	var.philo->time = current_time.tv_usec;
	// if (phil)
	// while (var.philo->philos_init != 0)
	// 	usleep(100);
	// if (var.philo_id % 2)
	// {
		take_left_fork(var);
		take_right_fork(var);
		start_eating(var);
	// }
	// else
		// usleep(var.philo->time_to_sleep / 2);
	// while (1)
	// 	philo_routine(var);
	return (0);
}

void	philo_routine(t_info var)
{
	take_left_fork(var);
	take_right_fork(var);
	start_eating(var);
	put_down_forks(var);
	start_sleeping(var);
	start_thinking(var);
}

int	take_left_fork(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(var.fork_left);
	printf("%dms    %d has taken a fork\n",
		(var.philo->time - current_time.tv_usec), var.philo_id);
	return (0);
}

int	take_right_fork(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(var.fork_right);
	printf("%dms    %d has taken a fork\n",
		(current_time.tv_usec - var.philo->time), var.philo_id);
	return (0);
}

int	start_eating(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	usleep(var.philo->time_to_eat);
	printf("%dms    %d is eating\n",
		(current_time.tv_usec - var.philo->time), var.philo_id);
	return (0);
}
