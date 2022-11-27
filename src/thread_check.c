/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:46:44 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 19:22:59 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

static int	death_check(t_philo philo)
{
	pthread_mutex_lock(&philo.info->timer_lock);
	if (time_ms()
		> philo.meal_timer + philo.info->time_die)
	{
		print_message('D', &philo);
		pthread_mutex_lock(&philo.info->die_lock);
		philo.info->die = 1;
		pthread_mutex_unlock(&philo.info->die_lock);
		pthread_mutex_unlock(&philo.info->print_lock);
		pthread_mutex_unlock(&philo.info->timer_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo.info->timer_lock);
	return (0);
}

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
		if (death_check(philo[i]))
			break ;
		if (i == philo[0].info->nbr_philos - 1)
			i = 0;
		if (philo[0].info->nbr_philos != 1)
			i++;
	}
}
