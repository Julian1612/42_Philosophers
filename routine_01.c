/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:53:32 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/27 20:24:15 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	philo_sleep(t_philo *philo)
{
	print_message('S', philo);
	my_usleep(philo->info->time_sleep, philo->info->nbr_philos);
}

void	philo_think(t_philo *philo)
{
	print_message('T', philo);
}
