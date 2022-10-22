/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:28 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 18:22:50 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *v)
{
	t_philo			philo;

	philo = *(t_philo *)v;
	while (philo.info->philos_init != 0)
		continue ;
	philo.info->time_start = time_ms();
	if (philo.philo_id % 2 != 0)
		my_sleep(philo.info->time_eat, philo.info->nbr_philos);
	philo_schedule(&philo);
	return (0);
}

void	philo_schedule(t_philo *philo)
{
	while (1)
	{
		if (take_right_fork(philo))
			return ;
		if (philo->info->nbr_philos > 1)
			my_sleep((philo->info->time_eat * 2), philo->info->nbr_philos);
		if (take_left_fork(philo))
			return ;
		if (start_eating(philo))
			return ;
		philo->meal_counter++;
		if (put_down_forks(philo))
			return ;
		if (start_sleeping(philo))
			return ;
		if (start_thinking(philo))
			return ;
	}
}

int	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	print_message('F', philo);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_message('F', philo);
	return (0);
}

int	start_eating(t_philo *philo)
{
	print_message('E', philo);
	usleep(philo->info->time_eat);
	return (0);
}
