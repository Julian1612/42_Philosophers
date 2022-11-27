/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:25:10 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 17:26:28 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	num;
	long	i;

	sign = 1;
	num = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\t' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = 1 - 2 * (nptr[i] == '-');
		i ++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - 48);
		i++;
	}
	if ((num * sign < 0) || (num * sign > INT_MAX))
		return (-1);
	else
		return (num * sign);
}

unsigned long	time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	my_usleep(unsigned long time, int nbr_philo)
{
	unsigned long	start_time;

	start_time = time_ms();
	if (nbr_philo > 50)
	{
		while ((start_time + time) > time_ms())
			usleep(200);
	}
	else
	{
		while ((start_time + time) > time_ms())
			usleep(50);
	}
}

void	print_message(char c, t_philo *philo)
{
	unsigned long	time;
	int				id;

	pthread_mutex_lock(&philo->info->print_lock);
	time = time_ms() - philo->info->time_start;
	id = philo->philo_id;
	if (c == 'F' && (philo->info->die < 1))
		printf("%lu   ms %d has taken a fork\n", time, id);
	else if (c == 'E' && (philo->info->die < 1))
		printf("%lu   ms %d is eating\n", time, id);
	else if (c == 'S' && (philo->info->die < 1))
		printf("%lu   ms %d is sleeping\n", time, id);
	else if (c == 'T' && (philo->info->die < 1))
		printf("%lu   ms %d is thinking\n", time, id);
	else if (c == 'D' && (philo->info->die < 1))
		printf("%lu   ms %d died\n", time, id);
	if (c != 'D')
		pthread_mutex_unlock(&philo->info->print_lock);
}
