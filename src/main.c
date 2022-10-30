/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:27 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/28 12:56:01 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	if (input_check(argc, argv))
		return (-1);
	info = init_info(argc, argv);
	if (info == NULL)
		return (-1);
	philo = (t_philo *) malloc(sizeof(t_philo) * info->nbr_philos);
	if (philo == NULL)
		return (-1);
	if (create_threads(info, philo))
		return (-1);
	thread_checker(philo);
	join_threads(philo);
	destroy_threads(philo);
	free_structs(philo, info);
	system("leaks philo");
	return (0);
}
