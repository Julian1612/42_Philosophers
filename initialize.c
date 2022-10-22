/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:49:00 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 12:09:23 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_info *info)
{
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nbr_philos);
	if (info->forks == NULL)
	{
		printf("Error!\ninit_forks()\n");
		return (-1);
	}
	return (0);
}

t_info	*init_info(int argc, char **argv)
{
	t_info	*info;

	info = (t_info *) malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->nbr_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->max_meals = ft_atoi(argv[5]);
	info->philos_init = 0;
	info->wait_flag = 0;
	info->fed_up = 0;
	info->die = 0;
	info->created_threads = 0;
	info->time_start = 0;
	return (info);
}

void	init_philo(t_info *info, t_philo *philo, int i)
{
	philo->info = info;
	philo->philo_id = i + 1;
	philo->fork_right = &info->forks[i];
	if (i == 0)
		philo->fork_left = &info->forks[info->nbr_philos - 1];
	else
		philo->fork_left = &info->forks[i - 1];
	pthread_mutex_init(philo->fork_right, NULL);
}
