/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:36:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/05/05 09:12:17 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_group1(t_philo *philo)
{
	while (!ft_death(philo))
	{
		if (ft_eat(philo))
			break ;
		if (philo->data->eatboo && philo->eat_times == 0)
			break ;
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
	}
}

void	ft_group3(t_philo *philo)
{
	while (!ft_death(philo))
	{
		if (ft_think(philo))
			break ;
		if (ft_eat(philo))
			break ;
		if (philo->data->eatboo && philo->eat_times == 0)
			break ;
		if (ft_sleep(philo))
			break ;
	}
}

void	ft_group2(t_philo *philo)
{
	while (!ft_death(philo))
	{
		if (ft_sleep(philo))
			break ;
		if (ft_think(philo))
			break ;
		if (ft_eat(philo))
			break ;
		if (philo->data->eatboo && philo->eat_times == 0)
			break ;
	}
}

int	ft_groups(int id, int total)
{
	if (total % 2 != 0 && id == total && total != 1)
		return (3);
	if (id % 2 != 0)
		return (1);
	if (id % 2 == 0)
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
