/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:30:48 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/17 17:19:41 by jschneid         ###   ########.fr       */
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
	pthread_mutex_t	mutex;

	if (input_check(argc, argv) == 1)
		return (1);
	initialize_variable(&var, argc, argv);
	pthread_mutex_init(&mutex, NULL);
	arr = (t_info *) malloc(sizeof(t_info) * var.number_of_philosophers);
	if (arr == NULL)
		return (1);
	th = malloc(sizeof(pthread_t *) * var.number_of_philosophers);
	if (th == NULL)
		return (1);
	i = 0;
	while (i < var.number_of_philosophers)
	{
		initialize_struct(&arr[i], &var, i);
		if (pthread_create(th + i, NULL, &philo_schedule, &arr[i]) != 0)
			return (1);
		i++;
	}
	j = 0;
	while (j < var.number_of_philosophers)
	{
		if (pthread_join(th[j], NULL) != 0)
			return (1);
		j++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}

void	*philo_schedule(void *v)
{
	t_info	var;

	var = *(t_info *)v;
	printf("Philo %d, hat links Gabel %d und rechts Gabel %d\n", var.philo_id, var.fork_left, var.fork_right);
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
