/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:01 by ecamara           #+#    #+#             */
/*   Updated: 2022/04/08 10:59:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int a)
{
	printf ("Error\n");
	if (a == 1)
		printf("Input was incorrect\n");
	else if (a == 2)
		printf("malloc\n");
	else if (a == 3)
		printf ("hilos\n");
	return (1);
}
