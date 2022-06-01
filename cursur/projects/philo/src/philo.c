/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:35:27 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/05 09:23:16 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_process(void *philo)
{
	t_philo			temp;
	int				group;

	temp = *(t_philo *)philo;
	pthread_mutex_unlock(temp.mutex);
	while (!temp.data->init_time.tv_sec && !temp.data->init_time.tv_usec)
		usleep(10);
	temp.time = temp.data->init_time;
	group = ft_groups(temp.id, temp.total);
	if (group == 1)
		ft_group1(&temp);
	else if (group == 2)
		ft_group2(&temp);
	else if (group == 3)
		ft_group3(&temp);
	return (NULL);
}

int	ft_input(t_data *data, char *argv[])
{
	data->init_time.tv_usec = 0;
	data->init_time.tv_sec = 0;
	data->total = ft_atoi_ph(argv[1]);
	data->t_die = ft_atoi_ph(argv[2]);
	data->t_eat = ft_atoi_ph(argv[3]);
	data->t_sleep = ft_atoi_ph(argv[4]);
	data->eat_times = 0;
	data->death = 0;
	data->eatboo = 0;
	if (argv[5] != NULL)
	{
		data->eat_times = ft_atoi_ph(argv[5]);
		data->eatboo = 1;
	}
	if (data->total < 0 || data->t_die <= 0
		|| data->t_eat <= 0 || data->t_sleep <= 0
		|| data->eat_times < 0)
		return (1);
	data->threads = malloc(sizeof(pthread_t) * data->total);
	data->m_death = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!data->m_death)
		return (1);
	pthread_mutex_init(data->m_death, NULL);
	return (data->total);
}

int	ft_data_create(t_data *data)
{
	int		i;

	data->forks = malloc(sizeof(t_forks) * data->total);
	i = 0;
	while (i < data->total)
	{
		data->forks[i].fork = 1;
		if (pthread_mutex_init(&data->forks[i].mutex, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_thread(t_data *data)
{
	t_philo			philo;
	struct timeval	now;
	int				i;

	i = -1;
	philo.mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo.mutex, NULL);
	while (++i < data->total)
	{
		pthread_mutex_lock(philo.mutex);
		philo.id = i + 1;
		ft_pass_data(data, &philo);
		if (pthread_create(&data->threads[i], NULL, &ft_process,
				&philo) != 0)
			return (1);
	}
	i = -1;
	gettimeofday(&now, NULL);
	data->init_time = now;
	while (++i < data->total)
		pthread_join(data->threads[i], NULL);
	pthread_mutex_destroy(philo.mutex);
	free(philo.mutex);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		error;

	error = 0;
	if (argc != 5 && argc != 6)
		return (ft_error(1));
	if (ft_check_input(argv))
		return (1);
	ft_input(&data, argv);
	if (data.total == 0)
		return (0);
	if (ft_data_create(&data))
		return (ft_error(2));
	if (ft_create_thread(&data))
		return (ft_error(3));
	ft_free_data(&data);
	return (0);
}
