/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:40:29 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/13 11:00:23 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_im_dead(t_philo *philo)
{
	struct timeval	now;
	int				now_2;

	gettimeofday(&now, NULL);
	now_2 = ft_to_ml(now) - ft_to_ml(philo->time);
	if (now_2 > philo->t_to_die)
	{
		printf("time passed : %d, time left: %d\n",now_2, philo->t_to_die);
		return (1);
	}
	return (0);
}

int	ft_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->death->m_death);
	if (philo->death->death)
	{
		pthread_mutex_unlock(&philo->death->m_death);
		return (1);
	}
	if (ft_im_dead(philo))
	{
		printf("%ld %d is dead, death = %d\n", ft_time(philo->g_time), philo->philo_num, philo->death->death);
		philo->death->death = 1;
		//printf("death = %d\n, p = %p", philo->death->death, &philo->death->death);
		pthread_mutex_unlock(&philo->death->m_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->death->m_death);
	return (0);
}

int	ft_to_ml(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_my_usleep(t_philo *philo, int time, int time_to_die)
{
	struct timeval	now;
	struct timeval	end;
	int				i;

	gettimeofday(&now, NULL);
	gettimeofday(&end, NULL);
	//printf("%ld %d start usleep\n", ft_time(philo->g_time), philo->philo_num);
	i = 0;
	while (ft_to_ml(end) - ft_to_ml(now) < time)
	{
		gettimeofday(&end, NULL);
		usleep(5);
		if (ft_to_ml(end) - ft_to_ml(now) - i < 10)
		{
			if (ft_death(philo))
			{
				printf("%ld %d dead usleep\n",  ft_time(philo->g_time), philo->philo_num);
				return (1);
			}
			i += 10;
		}
	}
	if (ft_death(philo))
	{
		printf("%ld %d dead usleep\n",  ft_time(philo->g_time), philo->philo_num);
		return (1);
	}
	//printf("%ld %d end usleep\n", ft_time(philo->g_time), philo->philo_num);
	return (0);
}

void	ft_routine(t_philo *philo, int num_of_philo, int philo_num, int group)
{
	while (1)
	{
		if (group == 3)
		{
			group = 2;
			if (ft_sleep(philo, philo_num, philo->t_to_sleep))
				break ;
		}
		if (group == 2)
		{
			group = 1;
			if (ft_think(philo, philo_num, philo->t_to_eat, philo->t_to_sleep))
				break ;
		}
		if (group == 1)
		{
			group = 3;
			if (ft_eat(philo, philo->t_to_eat, philo_num))
				break ;
		}
	}
}

int	ft_sleep(t_philo *philo, int philo_num, int t_to_sleep)
{
	if (ft_death(philo))
		return (1);
	printf("%ld %d is sleeping\n", ft_time(philo->g_time) , philo_num);
	if (ft_my_usleep(philo, t_to_sleep, philo_num))
		return (1);
	printf("%ld %d stoped sleeping\n", ft_time(philo->g_time) , philo_num);
	return (0);
}

void	ft_fork_handler(t_philo *philo, t_forks *forks, int left_fork, int a)
{
	int	right_fork;
	int	i;

	i = 0;
	right_fork = philo->philo_num - 1;
	while (i == 0)
	{
		pthread_mutex_lock(&forks[left_fork].mutex);
		pthread_mutex_lock(&forks[right_fork].mutex);
		if (forks[left_fork].fork != a && forks[right_fork].fork != a)
		{
			i = 1;
			forks[left_fork].fork = a;
			if (a == 0)
				printf("%ld %d has taken a fork\n", ft_time(philo->g_time),
					philo->philo_num);
			forks[right_fork].fork = a;
			if (a == 0)
				printf("%ld %d has taken a fork\n", ft_time(philo->g_time),	
					philo->philo_num);
		}
		pthread_mutex_unlock(&forks[left_fork].mutex);
		pthread_mutex_unlock(&forks[right_fork].mutex);
		ft_death(philo);
	}
}

int	ft_eat(t_philo *philo, int t_to_eat, int philo_num)
{
	int		left_fork;
	t_forks	*forks;

	if (ft_death(philo))
		return (1);
	forks = *philo->forks;
	left_fork = ft_f_left(philo_num, philo->num_of_philos);
	ft_fork_handler(philo, forks, left_fork, 0);
	gettimeofday(&philo->time, NULL);
	if (ft_my_usleep(philo, t_to_eat, philo_num))
		return (1);
	ft_fork_handler(philo, forks, left_fork, 1);
	return (0);
}

int	ft_think(t_philo *philo, int philo_num, int t_to_eat, int t_to_sleep)
{
	printf("%ld %d is thinking\n", ft_time(philo->g_time), philo_num);
	if (ft_death(philo))
		return (1);
	if (philo->num_of_philos % 2 != 0)
	{
		if (ft_my_usleep(philo, philo->t_to_eat * 2 - philo->t_to_sleep,
				philo_num))
			return (1);
	}
	else if (ft_my_usleep(philo, philo->t_to_eat - philo->t_to_sleep,
			philo_num))
		return (1);
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

int	ft_f_left(int philo_num, int num_of_philo)
{
	if (philo_num == 1)
		return (num_of_philo - 1);
	return (philo_num - 2);
}

int	ft_diff(int t_to_eat, int t_to_sleep)
{
	if (t_to_sleep - t_to_eat < 0)
		return (t_to_eat - t_to_sleep);
	return (t_to_sleep - t_to_eat);
}

long int	ft_time(t_time *g_time)
{
	struct timeval	now;
	long int		ms;

	gettimeofday(&now, NULL);
	ms = (now.tv_sec * 1000 + now.tv_usec / 1000)
		- (g_time->time.tv_sec * 1000 + g_time->time.tv_usec / 1000);
	return (ms);
}

void	*ft_process(void *philo)
{
	t_philo	*temp;
	int		num_of_philos;
	int		philo_num;
	int		group;

	temp = (t_philo *)philo;
	num_of_philos = temp->num_of_philos;
	philo_num = temp->philo_num;
	group = ft_groups(philo_num, num_of_philos);
	while (!temp->g_time->time.tv_usec && !temp->g_time->time.tv_sec)
		usleep(5);
	ft_routine(temp, num_of_philos, philo_num, group);
	return (NULL);
}

int	ft_data_create(t_data *data, int num_philos)
{
	int	i;
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

int	ft_input(t_data *data, char *argv[])
{
	data->num_of_philos = atoi(argv[1]);
	data->t_to_die = atoi(argv[2]);
	data->t_to_eat = atoi(argv[3]);
	data->t_to_sleep = atoi(argv[4]);
	return (data->num_of_philos);
}

void	ft_pass_data(t_data *data, t_death *death, int i, t_time *time)
{
	death->death = 0;
	pthread_mutex_init(&death->m_death, NULL);
	data->philos[i].death = death;
	//data->philos[i].death->death = 0;
	data->philos[i].forks = &data->forks;
	data->philos[i].num_of_philos = data->num_of_philos;
	data->philos[i].t_to_die = data->t_to_die;
	data->philos[i].t_to_eat = data->t_to_eat;
	data->philos[i].t_to_sleep = data->t_to_sleep;
	//pthread_mutex_init(&data->philos[i].mutex, NULL);
	data->philos[i].philo_num = i + 1;
	data->philos[i].g_time = time;
}

void	ft_free_thread(t_data *data, t_death *death, int num_of_philos)
{
	int	i;

	i = 0;
	printf("1\n");
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
	int i;
	t_forks	forks;
	t_time time;
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

int	main(int argc, char **argv)
{
	t_data	data;
	int		num_of_philos;
	int		error;

	error = 0;
	if (argc != 5 && argc != 6)
		return (ft_error(1));
	num_of_philos = ft_input(&data, argv);
	if (ft_data_create(&data, num_of_philos))
		return (ft_error(2));
	if (ft_create_thread(&data, num_of_philos))
		return (ft_error(3));
	system("leaks philo");
	return (0);
}