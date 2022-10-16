/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:30:48 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/16 19:42:21 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	// int			*forks_arr;
	// int			i;
	// int			j;
	// pthread_t	*th;
	t_var		var;

	if(input_check(argc, argv) == 1)
		return(1);
	initialize_variable(&var, argc, argv);
	printf("gg: %d\n", var.number_of_times_each_philosopher_must_eat);
	// forks_arr = initialize_forks();
    // th = malloc(sizeof(pthread_t *) * var.number_of_philosophers);
	// i = 0;
	// while (i < var.number_of_philosophers)
	// {
	// 	if (pthread_create(th + i, NULL, &test, NULL) != 0)
	// 		return (1);
    //     i++;
	// }
	// j = 0;
	// while (j < var.number_of_philosophers)
	// {
	// 	if (pthread_join(th[j], NULL) != 0)
	// 		return (1);
    //     j++;
	// }
	// return (0);
}

void	*test(void * v)
{
	(void) v;
	printf("lol\n");
	return (0);
}
