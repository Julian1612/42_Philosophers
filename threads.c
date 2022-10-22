/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:30:53 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 16:55:20 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_info *info)
{
	int				i;
	pthread_t		*thread;
	t_philo			*philo;

	philo = malloc(sizeof(t_philo) * info->nbr_philos);
	if (philo == NULL)
		return (-1);
	thread = malloc(sizeof(pthread_t) * info->nbr_philos);
	if (thread == NULL)
		return (-1);
	i = 0;
	while (i < info->nbr_philos)
	{
		init_philo(info, &philo[i], i);
		info->time_start = time_ms();
		if (pthread_create(&thread[i], NULL, &routine, &philo[i]) != 0)
			return (-1);
		if ((i + 1) == info->nbr_philos)
			info->philos_init = 0;
		i++;
	}
	return (0);
}
