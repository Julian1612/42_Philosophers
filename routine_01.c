/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:53:32 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 18:04:52 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_sleeping(t_philo *philo)
{
	print_message('S', philo);
	my_sleep(philo->info->time_sleep, philo->info->nbr_philos);
	return (0);
}

int	start_thinking(t_philo *philo)
{
	print_message('T', philo);
	return (0);
}

int	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (0);
}
