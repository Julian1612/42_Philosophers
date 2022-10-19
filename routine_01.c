/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:55:35 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 13:34:15 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_sleeping(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	usleep(var.philo->time_to_sleep);
	printf("%dms    %d is sleeping\n",
		(current_time.tv_usec - var.philo->time), var.philo_id);
	return (0);
}

int	start_thinking(t_info var)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%dms    %d is thinking\n",
		(current_time.tv_usec - var.philo->time), var.philo_id);
	return (0);
}

int	put_down_forks(t_info var)
{
	pthread_mutex_unlock(var.fork_left);
	pthread_mutex_unlock(var.fork_right);
	return (0);
}
