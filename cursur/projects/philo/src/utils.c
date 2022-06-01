/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:46:03 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/05 09:21:49 by ecamara          ###   ########.fr       */
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

int	ft_f_left(int id, int total)
{
	if (id == 1)
		return (total - 1);
	return (id - 2);
}

void	ft_pass_data(t_data *data, t_philo *philo)
{
	philo->forks = data->forks;
	philo->total = data->total;
	philo->data = data;
	philo->eat_times = data->eat_times;
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
	free(data->forks);
	free(data->threads);
	pthread_mutex_destroy(data->m_death);
	free(data->m_death);
}
