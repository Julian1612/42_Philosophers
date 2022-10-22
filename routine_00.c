/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:28 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 13:57:16 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *v)
{
	t_philo			philo;

	philo = *(t_philo *)v;
	while (philo.info->philos_init != 0)
		usleep(100);
	if (philo.philo_id % 2)
	{
		take_left_fork(&philo);
		take_right_fork(&philo);
		start_eating(&philo);
	}
	else
		usleep(philo.info->time_sleep / 2);
	philo_routine(philo);
	return (0);
}

void	philo_schedule(t_philo *philo)
{
	while (1)
	{
		/* code */
	}
}

int	take_left_fork(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(philo->fork_left);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(philo->fork_right);
	return (0);
}

int	start_eating(t_philo *philo)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	usleep(philo->info->time_eat);
	return (0);
}
