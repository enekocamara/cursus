/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:35:27 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/15 10:52:04 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		num_of_philos;
	int		error;

	error = 0;
	if (argc != 5 && argc != 6)
		return (ft_error(1));
	if (ft_check_input(argv))
		return (1);
	num_of_philos = ft_input(&data, argv);
	if (ft_data_create(&data, num_of_philos))
		return (ft_error(2));
	if (ft_create_thread(&data, num_of_philos))
		return (ft_error(3));
	return (0);
}
