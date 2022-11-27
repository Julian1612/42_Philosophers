/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:58:02 by jschneid          #+#    #+#             */
/*   Updated: 2022/11/27 17:26:39 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

static int	str_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Error!\nInvalid input.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	nbr_size_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0
		|| ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| (argc == 6 && ft_atoi(argv[5]) < 0))
	{
		printf("Error!\nJust use intiger values.\n");
		return (1);
	}
	else
		return (0);
}

int	input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error!\nWrong number of input values.\n");
		return (-1);
	}
	else if (nbr_size_check(argc, argv))
		return (-1);
	else if (str_check(argv[1]) || str_check(argv[2])
		|| str_check(argv[3]) || str_check(argv[4]))
		return (-1);
	else if (ft_atoi(argv[1]) < 1)
	{
		printf("Error!\nAt least 1 philosopher is required\n");
		return (-1);
	}
	else if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
		|| (argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		printf("Error!\nNegative numbers or zero is not a valid input\n");
		return (-1);
	}
	return (0);
}
