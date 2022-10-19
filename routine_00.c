/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:47:31 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 16:20:53 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_schedule(void *v)
{
	t_info			var;
	struct timeval	current_time;

	var = *(t_info *)v;
	gettimeofday(&current_time, NULL);
	while (var.philo->philos_init != 0)
		usleep(100);
	if (var.philo_id % 2)
	{
		take_left_fork(var);
		take_right_fork(var);
		start_eating(var);
	}
	else
		usleep(var.philo->time_to_sleep / 2);
	while (1)
		philo_routine(var);
	return (0);
}

int	time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

void	philo_routine(t_info var)
{
	start_thinking(var);
	start_sleeping(var);
	put_down_forks(var);
	start_eating(var);
	take_right_fork(var);
	take_left_fork(var);
}

int	take_left_fork(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(var.fork_left);
	printf("%dms	%d has taken a fork\n", time_ms() - var.philo->time, var.philo_id);
	return (0);
}

int	take_right_fork(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(var.fork_right);
	printf("%dms	%d has taken a fork\n",
		time_ms() - var.philo->time, var.philo_id);
	return (0);
}

int	start_eating(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%dms	%d is eating\n",
		time_ms() - var.philo->time, var.philo_id);
	usleep(var.philo->time_to_eat);
	return (0);
}
