/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:46:44 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/24 16:47:31 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	thread_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].info->fed_up == philo->info->nbr_philos)
		{
			printf("All Philosophers are fed up\n");
			return ;
		}
		pthread_mutex_lock(&philo->info->eat_lock);
		if (time_ms()
			> philo[i].meal_timer + philo[i].info->time_die)
		{
			print_message('D', &philo[i]);
			philo[i].info->die = 1;
			pthread_mutex_unlock(&philo[i].info->print_lock);
			return ;
		}
		pthread_mutex_unlock(&philo->info->eat_lock);
		if (i == philo[0].info->nbr_philos - 1)
			i = 0;
		if (philo[0].info->nbr_philos != 1)
			i++;
	}
}
