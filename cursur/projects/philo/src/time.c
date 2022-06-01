/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:37:53 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/05 09:15:32 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_my_usleep(t_philo *philo, int time)
{
	struct timeval	now;
	struct timeval	end;
	int				i;

	gettimeofday(&now, NULL);
	gettimeofday(&end, NULL);
	i = 0;
	while (ft_to_ml(end) - ft_to_ml(now) < time)
	{
		usleep(100);
		gettimeofday(&end, NULL);
		if (ft_to_ml(end) - ft_to_ml(now) - i < 10)
		{
			i += 10;
			if (ft_death(philo))
				return (1);
		}
	}
	if (ft_death(philo))
		return (1);
	return (0);
}

long int	ft_to_ml(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long int	ft_time(t_philo *philo)
{
	struct timeval	now;
	long int		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000 + now.tv_usec / 1000)
		- (philo->data->init_time.tv_sec * 1000
			+ philo->data->init_time.tv_usec / 1000);
	return (time);
}

int	ft_death(t_philo *philo)
{
	long int		time;
	struct timeval	now;

	pthread_mutex_lock(philo->data->m_death);
	if (philo->data->death)
	{
		pthread_mutex_unlock(philo->data->m_death);
		return (1);
	}
	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000 + now.tv_usec / 1000)
		- (philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000);
	if (time <= philo->data->t_die)
	{
		pthread_mutex_unlock(philo->data->m_death);
		return (0);
	}
	philo->data->death = 1;
	printf("%ld %d died\n", ft_time(philo), philo->id);
	pthread_mutex_unlock(philo->data->m_death);
	return (1);
}
