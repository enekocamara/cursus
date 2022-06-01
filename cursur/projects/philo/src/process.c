/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:53 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/05 09:15:07 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_think(t_philo *philo)
{
	printf("%ld %d is thinking\n", ft_time(philo), philo->id);
	if (philo->data->total % 2 != 0)
	{
		if (ft_my_usleep(philo, ((philo->data->t_eat * 2)
					- philo->data->t_sleep)))
			return (1);
	}
	else if (philo->data->total % 2 == 0)
	{
		if (ft_my_usleep(philo, (philo->data->t_eat - philo->data->t_sleep)))
			return (1);
	}
	return (0);
}

int	ft_eat(t_philo *philo)
{
	struct timeval	now;

	if (ft_fork_handler(philo, 0))
		return (1);
	gettimeofday(&now, NULL);
	philo->time = now;
	printf("%ld %d is eating\n", ft_time(philo), philo->id);
	if (philo->data->eatboo)
		philo->eat_times--;
	if (ft_my_usleep(philo, philo->data->t_eat))
		return (1);
	ft_fork_handler(philo, 1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	printf("%ld %d is sleeping\n", ft_time(philo), philo->id);
	if (ft_my_usleep(philo, philo->data->t_sleep))
		return (1);
	return (0);
}

int	ft_fork_handler2(t_philo *philo, int boo)
{
	int	fork;

	if (philo->id == 1)
		fork = philo->data->total - 1;
	else
		fork = philo->id - 2;
	if (philo->forks[fork].fork != boo)
	{
		pthread_mutex_lock(&philo->forks[fork].mutex);
		philo->forks[fork].fork = boo;
		if (boo == 0)
			printf("%ld %d has taken a fork\n", ft_time(philo), philo->id);
		pthread_mutex_unlock(&philo->forks[fork].mutex);
		return (1);
	}
	return (0);
}

int	ft_fork_handler(t_philo *philo, int boo)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		pthread_mutex_lock(&philo->forks[philo->id - 1].mutex);
		if (philo->forks[philo->id - 1].fork != boo)
		{
			philo->forks[philo->id - 1].fork = boo;
			pthread_mutex_unlock(&philo->forks[philo->id - 1].mutex);
			if (boo == 0)
				printf("%ld %d has taken a fork\n", ft_time(philo), philo->id);
			if (philo->data->total != 1)
			{
				ft_fork_handler2(philo, boo);
				i = 1;
			}
		}
		pthread_mutex_unlock(&philo->forks[philo->id - 1].mutex);
		if (ft_death(philo))
			return (1);
		usleep(20);
	}
	return (0);
}
