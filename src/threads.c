/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:30:53 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/27 12:29:45 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	create_threads(t_info *info, t_philo *philo)
{
	int				i;
	pthread_t		*thread;

	if (init_forks(info))
		return (-1);
	thread = malloc(sizeof(pthread_t) * info->nbr_philos);
	if (thread == NULL)
		return (-1);
	i = 0;
	while (i < info->nbr_philos)
	{
		init_philo(info, &philo[i], i);
		info->time_start = time_ms();
		if (pthread_create(&thread[i], NULL, &routine, &philo[i]))
			return (-1);
		i++;
	}
	info->philos_init = 1;
	return (0);
}
