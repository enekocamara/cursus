/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:37:53 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/11 13:58:55 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_diff(int t_to_eat, int t_to_sleep)
{
	if (t_to_sleep - t_to_eat < 0)
		return (t_to_eat - t_to_sleep);
	return (t_to_sleep - t_to_eat);
}

int	ft_my_usleep(t_philo *philo, int time, int time_to_die)
{
	struct timeval	now;
	struct timeval	end;
	int				i;

	(void)time_to_die;
	gettimeofday(&now, NULL);
	gettimeofday(&end, NULL);
	i = 0;
	while (ft_to_ml(end) - ft_to_ml(now) < time)
	{
		gettimeofday(&end, NULL);
		usleep(5);
		if (ft_to_ml(end) - ft_to_ml(now) - i < 10)
		{
			if (ft_death(philo))
				return (1);
			i += 10;
		}
	}
	if (ft_death(philo))
		return (1);
	return (0);
}

int	ft_to_ml(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
