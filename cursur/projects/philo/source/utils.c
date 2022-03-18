/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:46:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/18 10:41:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_ph(const char *str)
{
	int					c;
	int					i;
	unsigned long int	num;

	c = 0;
	i = 1;
	num = 0;
	while (str[c] && (str[c] == ' ' || (str[c] <= 13 && str[c] >= 9)))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			i *= -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0' && str[c] != '\0')
	{
		num = (num * 10) + (str[c] - '0');
		c++;
	}
	if (num > 9223372036854775807 && i == -1)
		return (0);
	if (num > 9223372036854775807 && i == 1)
		return (-1);
	return (num * i);
}

int	ft_f_left(int philo_num, int num_of_philo)
{
	if (philo_num == 1)
		return (num_of_philo - 1);
	return (philo_num - 2);
}
