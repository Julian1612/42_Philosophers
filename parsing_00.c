/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:11:34 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/17 17:53:24 by jschneid         ###   ########.fr       */
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
	var->forks_arr = malloc(sizeof(int *) * var->number_of_philosophers);
	if (var->forks_arr == NULL)
		return (1);
	memset(var->forks_arr, 0, var->number_of_philosophers * sizeof (int *));
	return (0);
}

void	initialize_struct(t_info *arr, t_philo *var, int i)
{
	(void) var;
	arr->philo_id = i + 1;
	arr->fork_right = i;
	if (i == 0)
		arr->fork_left = var->number_of_philosophers - 1;
	else
		arr->fork_left = i - 1;
}
