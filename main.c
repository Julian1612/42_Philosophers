/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschneid <jschneid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:07:27 by jschneid          #+#    #+#             */
/*   Updated: 2022/10/22 18:22:28 by jschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (input_check(argc, argv))
		return (-1);
	info = init_info(argc, argv);
	if (info == NULL)
		return (-1);
	if (init_forks(info))
		return (-1);
	if (create_threads(info))
		return (-1);
	return (0);
}
