/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:46:44 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/27 12:44:07 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

void	thread_checker(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (philo[i].meal_counter == philo->info->max_meals)
		{
			pthread_mutex_lock(&philo->info->fed_up_lock);
			philo->info->die++;
			pthread_mutex_unlock(&philo->info->fed_up_lock);

		}
	}
	i++;
}
