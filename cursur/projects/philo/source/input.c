/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/18 10:41:16 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_input(t_data *data, char *argv[])
{
	data->num_of_philos = ft_atoi_ph(argv[1]);
	data->t_to_die = ft_atoi_ph(argv[2]);
	data->t_to_eat = ft_atoi_ph(argv[3]);
	data->t_to_sleep = ft_atoi_ph(argv[4]);
	if (argv[5] != NULL)
	{
		data->boo_eat = 1;
		data->num_eat = ft_atoi_ph(argv[5]);
	}
	else
		data->boo_eat = 0;
	return (data->num_of_philos);
}

void	ft_pass_data(t_data *data, t_death *death, int i, t_time *time)
{
	death->death = 0;
	pthread_mutex_init(&death->m_death, NULL);
	data->philos[i].death = death;
	data->philos[i].forks = &data->forks;
	data->philos[i].num_of_philos = data->num_of_philos;
	data->philos[i].t_to_die = data->t_to_die;
	data->philos[i].t_to_eat = data->t_to_eat;
	data->philos[i].t_to_sleep = data->t_to_sleep;
	data->philos[i].philo_num = i + 1;
	data->philos[i].g_time = time;
	if (data->boo_eat)
	{
		data->philos[i].num_eat = data->num_eat;
		data->philos[i].boo_eat = data->boo_eat;
	}
	printf("num eat = %d, boo = %d\n", data->philos[i].num_eat,
		data->philos[i].boo_eat);
}

int	ft_data_create(t_data *data, int num_philos)
{
	int		i;
	t_forks	*forks;

	data->hilos = malloc (sizeof(pthread_t) * num_philos);
	data->philos = malloc(sizeof(t_philo) * num_philos);
	forks = malloc(sizeof(t_forks) * num_philos);
	data->forks = forks;
	if (!data->hilos || !data->philos || !data->forks)
		return (1);
	i = 0;
	while (i < num_philos)
	{
		forks[i].fork = 1;
		if (pthread_mutex_init(&forks[i].mutex, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	ft_groups(int philo_num, int num_of_philo)
{
	if (num_of_philo % 2 != 0 && philo_num == num_of_philo)
		return (3);
	if (philo_num % 2 != 0)
		return (1);
	if (philo_num % 2 == 0)
		return (2);
	return (0);
}

int	ft_check_input(char	*argv[])
{
	int	i;
	int	j;

	j = 1;
	while (argv[j] != NULL)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] > 57 || argv[j][i] < 48)
				return (ft_error(1));
			i++;
		}
		j++;
	}
	return (0);
}
