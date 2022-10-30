/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:58:02 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/27 12:29:08 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

int	input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error!\n");
		printf("Wrong number of input values.");
		printf(" At least 4 and a maximum of 5 values must be entered\n");
		return (-1);
	}
	else if (ft_atoi(argv[1]) < 1)
	{
		printf("Error!\n");
		printf("At least 1 philosopher is required\n");
		return (-1);
	}
	else if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		printf("Error!\n");
		printf("Negative numbers or zero is not a valid input\n");
		return (-1);
	}
	return (0);
}
