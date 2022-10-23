/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:53:32 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/23 17:03:33 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print_message('S', philo);
	pthread_mutex_unlock(&philo->info->print_lock);
	my_sleep(philo->info->time_sleep, philo->info->nbr_philos);

}

void	start_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->print_lock);
	print_message('T', philo);
	pthread_mutex_unlock(&philo->info->print_lock);
}
