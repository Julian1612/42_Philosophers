/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:46:44 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 14:20:43 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	thread_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->info->fed_up_lock);
		if (philo[i].info->fed_up == philo->info->nbr_philos)
		{
			printf("All Philosophers are fed up\n");
			pthread_mutex_unlock(&philo->info->fed_up_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->info->fed_up_lock);
		pthread_mutex_lock(&philo[i].info->timer_lock);
		if (time_ms()
			> philo[i].meal_timer + philo[i].info->time_die)
		{
			print_message('D', &philo[i]);
			pthread_mutex_lock(&philo[i].info->die_lock);
			philo[i].info->die = 1;
			pthread_mutex_unlock(&philo[i].info->die_lock);
			pthread_mutex_unlock(&philo[i].info->print_lock);
			pthread_mutex_unlock(&philo[i].info->timer_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->info->timer_lock);
		if (i == philo[0].info->nbr_philos - 1)
			i = 0;
		if (philo[0].info->nbr_philos != 1)
			i++;
	}
}
