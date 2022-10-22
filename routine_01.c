/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:53:32 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 13:54:04 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_sleeping(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	usleep(var.philo->time_to_sleep);
	printf("%dms	%d is sleeping\n",
		time_ms() - var.philo->time, var.philo_id);
	return (0);
}

int	start_thinking(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%dms	%d is thinking\n",
		time_ms() - var.philo->time, var.philo_id);
	return (0);
}

int	put_down_forks(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_unlock(var.fork_left);
	pthread_mutex_unlock(var.fork_right);
	var.last_time_eaten = current_time.tv_usec;
	return (0);
}
