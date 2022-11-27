/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:27:28 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 15:06:47 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	*routine(void *v)
{
	t_philo			*philo;

	philo = (t_philo *)v;
	pthread_mutex_lock(&philo->info->wait_lock);
	if (philo->info->wait_flag == 0)
	{
		pthread_mutex_unlock(&philo->info->wait_lock);
		while (1)
		{
			pthread_mutex_lock(&philo->info->wait_lock);
			if (philo->info->philos_init == 1)
				break ;
			pthread_mutex_unlock(&philo->info->wait_lock);
		}
		philo->info->wait_flag = 1;
	}
	pthread_mutex_unlock(&philo->info->wait_lock);
	pthread_mutex_lock(&philo->info->timer_lock);
	philo->meal_timer = time_ms();
	pthread_mutex_unlock(&philo->info->timer_lock);
	if (philo->philo_id % 2 == 0)
		my_usleep((philo->info->time_eat), philo->info->nbr_philos);
	philo_schedule(philo);
	return (NULL);
}

void	philo_schedule(t_philo *philo)
{
	while (1)
	{
		philo_eat(philo);
		pthread_mutex_lock(&philo->info->fed_up_lock);
		if (philo->meal_counter == philo->info->max_meals)
		{
			philo->info->fed_up++;
			pthread_mutex_unlock(&philo->info->fed_up_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->info->fed_up_lock);
		pthread_mutex_lock(&philo->info->die_lock);
		if (philo->info->die > 0)
		{
			pthread_mutex_unlock(&philo->info->die_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->info->die_lock);
		philo_sleep(philo);
		philo_think(philo);
	}
}

// check routine if everything works as aspected

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	print_message('F', philo);
	if (philo->info->nbr_philos == 1)
	{
		my_usleep((philo->info->time_eat * 10), philo->info->nbr_philos);
		pthread_mutex_unlock(philo->fork_right);
		return ;
	}
	pthread_mutex_lock(philo->fork_left);
	print_message('F', philo);
	print_message('E', philo);
	philo->meal_counter++;
	pthread_mutex_lock(&philo->info->timer_lock);
	philo->meal_timer = time_ms();
	pthread_mutex_unlock(&philo->info->timer_lock);
	my_usleep(philo->info->time_eat, philo->info->nbr_philos);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
