/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:49:00 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 11:31:01 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

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

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->nbr_philos = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->max_meals = ft_atoi(argv[5]);
	else
		info->max_meals = INT_MAX;
	info->philos_init = 0;
	info->wait_flag = 0;
	info->fed_up = 0;
	info->die = 0;
	info->created_threads = 0;
	info->time_start = 0;
	pthread_mutex_init(&info->print_lock, NULL);
	pthread_mutex_init(&info->fed_up_lock, NULL);
	pthread_mutex_init(&info->wait_lock, NULL);
	pthread_mutex_init(&info->timer_lock, NULL);
	pthread_mutex_init(&info->die_lock, NULL);
	return (info);
}

void	init_philo(t_info *info, t_philo *philo, int i)
{
	philo->info = info;
	philo->philo_id = i + 1;
	philo->meal_counter = 0;
	philo->meal_timer = 0;
	philo->fork_right = &info->forks[i];
	if (i == 0)
		philo->fork_left = &info->forks[info->nbr_philos - 1];
	else
		philo->fork_left = &info->forks[i - 1];
	pthread_mutex_init(philo->fork_left, NULL);
}
