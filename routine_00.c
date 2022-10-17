/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:47:31 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/17 19:56:01 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_schedule(void *v)
{
	t_info	var;

	var = *(t_info *)v;
	while (var.philos_init == 1)
		usleep(1);
	printf("Philo %d, hat links Gabel %d und rechts Gabel %d\n", var.philo_id, var.fork_left, var.fork_right);

	return (0);
}

void	take_fork()
{

}
