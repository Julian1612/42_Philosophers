/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:11:34 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 13:41:19 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (1);
	else if (ft_atoi(argv[1]) < 2)
		return (2);
	else if (ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (3);
	return (0);
}

void	initialize_variable(t_philo *var, int argc, char *argv[])
{
	var->number_of_philosophers = ft_atoi(argv[1]);
	var->time_to_die = ft_atoi(argv[2]);
	var->time_to_eat = ft_atoi(argv[3]);
	var->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		var->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	initialize_forks(var);
}

int	initialize_forks(t_philo *var)
{
	var->arr_mutex_fork = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * var->number_of_philosophers);
	if (var->arr_mutex_fork == NULL)
		return (1);
	return (0);
}

void	initialize_struct(t_info *arr, t_philo *var, int i)
{
	arr->philo = var;
	arr->philo_id = i + 1;
	arr->fork_right = &var->arr_mutex_fork[i];
	if (i == 0)
		arr->fork_left = &var->arr_mutex_fork[var->number_of_philosophers - 1];
	else
		arr->fork_left = &var->arr_mutex_fork[i - 1];
	pthread_mutex_init(arr->fork_left, NULL);
}
