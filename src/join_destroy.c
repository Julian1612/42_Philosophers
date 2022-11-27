/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:38:16 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 14:13:52 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	join_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].info->nbr_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf("Error\npthread_join()\n");
			return ;
		}
		i++;
	}
}

void	destroy_threads(t_philo *philo) //mutex!!!
{
	int	i;

	i = 0;
	while (i < philo[0].info->nbr_philos)
	{
		pthread_mutex_destroy(philo[i].fork_left);
		i++;
	}
	pthread_mutex_destroy(&philo[0].info->print_lock);
	pthread_mutex_destroy(&philo->info->wait_lock);
	pthread_mutex_destroy(&philo->info->fed_up_lock);
	pthread_mutex_destroy(&philo->info->die_lock);
}

void	free_structs(t_philo *philo, t_info *info)
{
	free(info->forks);
	free(philo);
	free(info);
}
