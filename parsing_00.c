/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:11:34 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/16 19:37:56 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(int argc, char *argv[])
{
	if (argc < 4 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) < 2)
		return (2);
	else if (ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		return (3);
	else
		return (0);
}

void	initialize_variable(t_var *var, int argc, char *argv[])
{
	var->number_of_philosophers = ft_atoi(argv[1]);
	var->time_to_die = ft_atoi(argv[2]);
	var->time_to_eat = ft_atoi(argv[3]);
	var->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		var->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

int	*initialize_forks(void)
{
	int		*arr;
	t_var	var;

	arr = malloc(sizeof(int *) * var.number_of_philosophers);
	if (arr == NULL)
		return (NULL);
	memset(arr, 0, var.number_of_philosophers * sizeof (int));
	return (arr);
}
