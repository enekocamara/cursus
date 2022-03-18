/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:38:58 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/15 11:32:14 by ecamara          ###   ########.fr       */
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
		printf("time passed : %d, time left: %d\n", now_2, philo->t_to_die);
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
		printf("%ld %d died\n", ft_time(philo->g_time), philo->philo_num);
		philo->death->death = 1;
		pthread_mutex_unlock(&philo->death->m_death);
		return (1);
	}
	pthread_mutex_unlock(&philo->death->m_death);
	return (0);
}
