/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:41:22 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/18 10:39:22 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_thread(t_data *data, t_death *death, int num_of_philos)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&death->m_death);
	while (i < num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
	free(data->forks);
}

int	ft_create_thread(t_data *data, int num_philos)
{
	int		i;
	t_time	time;
	t_death	death;

	i = 0;
	time.time.tv_sec = 0;
	time.time.tv_usec = 0;
	while (i < num_philos)
	{
		ft_pass_data(data, &death, i, &time);
		if (pthread_create(&data->hilos[i], NULL, ft_process,
				&data->philos[i]))
			return (1);
		i++;
	}
	gettimeofday(&time.time, NULL);
	i = 0;
	while (i < num_philos)
	{
		pthread_join(data->hilos[i], NULL);
		i++;
	}
	ft_free_thread(data, &death, num_philos);
	return (0);
}

int	ft_fork_handler(t_philo *philo, t_forks *forks, int left_fork, int a)
{
	int	right_fork;
	int	i;
	int	j;

	i = 0;
	j = 0;
	right_fork = philo->philo_num - 1;
	while (i == 0 || j == 0)
	{
		pthread_mutex_lock(&forks[left_fork].mutex);
		if (philo->num_of_philos != 1)
			pthread_mutex_lock(&forks[right_fork].mutex);
		if (forks[left_fork].fork != a)
			i = ft_fork_handler2(philo, forks, left_fork, a);
		pthread_mutex_unlock(&forks[left_fork].mutex);
		if (philo->num_of_philos != 1)
		{
			j = ft_fork_handler3(philo, forks, right_fork, a);
			pthread_mutex_unlock(&forks[right_fork].mutex);
		}
		if (ft_death(philo))
			return (1);
	}
	return (0);
}

int	ft_fork_handler2(t_philo *philo, t_forks *forks, int left_fork, int a)
{
	forks[left_fork].fork = a;
	if (a == 0)
		printf("%ld %d has taken a fork\n", ft_time(philo->g_time),
			philo->philo_num);
	return (1);
}

int	ft_fork_handler3(t_philo *philo, t_forks *forks, int right_fork, int a)
{
	if (forks[right_fork].fork != a)
	{
		forks[right_fork].fork = a;
		if (a == 0)
			printf("%ld %d has taken a fork\n", ft_time(philo->g_time),
				philo->philo_num);
		return (1);
	}
	return (0);
}
