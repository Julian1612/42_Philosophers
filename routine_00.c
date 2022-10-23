/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:28 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/23 17:09:08 by jschneid         ###   ########.fr       */
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
		start_eating(philo);
		if (philo->meal_counter == philo->info->max_meals)
		{
			pthread_mutex_lock(&philo->info->fed_up_lock);
			philo->info->fed_up++;
			pthread_mutex_unlock(&philo->info->fed_up_lock);
			return ;
		}
		if (philo->info->die > 0)
			return ;
		start_sleeping(philo);
		start_thinking(philo);
	}
}

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_message('F', philo);
	if (philo->info->nbr_philos == 1)
			my_sleep((philo->info->time_eat * 2), philo->info->nbr_philos);
	pthread_mutex_lock(philo->fork_left);
	print_message('F', philo);
	philo->meal_counter++;
	print_message('E', philo);
	philo->last_meal = time_ms();
	usleep(philo->info->time_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
