/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:49:00 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/21 11:52:03 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_info *info)
{
	info->forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * info->nbr_philos);
	if (info->nbr_philos == NULL)
	{
		printf("Error!\n init_forks()");
		return (-1);
	}
	return (0);
}
