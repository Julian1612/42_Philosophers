/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:30:53 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 13:53:30 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	create_threads(t_info *info, t_philo *philo)
{
	int	i;

	if (init_forks(info))
		return (-1);
	i = 0;
	while (i < info->nbr_philos)
	{
		init_philo(info, &philo[i], i);
		info->time_start = time_ms();
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			return (-1);
		i++;
	}
	pthread_mutex_lock(&philo->info->wait_lock);
	info->philos_init = 1;
	pthread_mutex_unlock(&philo->info->wait_lock);
	usleep(50000);
	return (0);
}
