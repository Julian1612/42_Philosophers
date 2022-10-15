/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:30:48 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/15 15:38:18 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	struct timeval	current_time;

	(void) argv;
	(void) argc;
	gettimeofday(&current_time, NULL);
	printf("Seconds: %ld\nMicroseconds: %d", current_time.tv_sec, current_time.tv_usec);
	return (0);
}
