/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:39:53 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/18 10:41:31 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_think(t_philo *philo, int philo_num, int t_to_eat, int t_to_sleep)
{
	if (ft_death(philo))
		return (1);
	printf("%ld %d is thinking\n", ft_time(philo->g_time), philo_num);
	if (philo->num_of_philos % 2 != 0)
	{
		if (ft_my_usleep(philo, philo->t_to_eat * 2 - philo->t_to_sleep,
				philo_num))
			return (1);
	}
	else if (ft_my_usleep(philo, philo->t_to_eat - philo->t_to_sleep,
			philo_num))
		return (1);
	if (ft_death(philo))
		return (1);
	(void)t_to_eat;
	(void)t_to_sleep;
	return (0);
}

int	ft_eat(t_philo *philo, int t_to_eat, int philo_num)
{
	int		left_fork;
	t_forks	*forks;

	if (ft_death(philo))
		return (1);
	forks = *philo->forks;
	left_fork = ft_f_left(philo_num, philo->num_of_philos);
	if (ft_fork_handler(philo, forks, left_fork, 0))
		return (1);
	printf("%ld %d is eating\n", ft_time(philo->g_time), philo_num);
	gettimeofday(&philo->time, NULL);
	if (ft_my_usleep(philo, t_to_eat, philo_num))
		return (1);
	ft_fork_handler(philo, forks, left_fork, 1);
	return (0);
}

int	ft_sleep(t_philo *philo, int philo_num, int t_to_sleep)
{
	if (ft_death(philo))
		return (1);
	printf("%ld %d is sleeping\n", ft_time(philo->g_time), philo_num);
	if (ft_my_usleep(philo, t_to_sleep, philo_num))
		return (1);
	printf("%ld %d stoped sleeping\n", ft_time(philo->g_time), philo_num);
	return (0);
}

void	ft_routine(t_philo *philo, int num_of_philo, int philo_num, int group)
{
	gettimeofday(&philo->time, NULL);
	(void)num_of_philo;
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
			if (ft_eat(philo, philo->t_to_eat, philo_num)
				|| (philo->boo_eat && philo->num_eat == 1))
				break ;
			philo->num_eat--;
		}
	}
}
