/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:30:48 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/19 13:37:58 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	int				i;
	int				j;
	pthread_t		*th;
	t_philo			var;
	t_info			*arr;

	if (input_check(argc, argv) == 1)
		return (1);
	initialize_variable(&var, argc, argv);
	arr = (t_info *) malloc(sizeof(t_info) * var.number_of_philosophers);
	if (arr == NULL)
		return (1);
	th = malloc(sizeof(pthread_t *) * var.number_of_philosophers);
	if (th == NULL)
		return (1);
	arr->philo = &var;
	arr->philo->philos_init = 1;
	i = 0;
	initialize_forks(&var);
	while (i < var.number_of_philosophers)
	{
		initialize_struct(&arr[i], &var, i);
		if (pthread_create(th + i, NULL, &philo_schedule, &arr[i]) != 0)
			return (1);
		if (i + 1 == var.number_of_philosophers)
			var.philos_init = 0;
		i++;
	}
	j = 0;
	while (j < var.number_of_philosophers)
	{
		if (pthread_join(th[j], NULL) != 0)
			return (1);
		j++;
	}
	pthread_mutex_destroy(var.arr_mutex_fork);
	free(arr);
	free(th);
	return (0);
}
