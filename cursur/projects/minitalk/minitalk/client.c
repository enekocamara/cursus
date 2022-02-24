/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:07:42 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/17 09:12:56 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	ft_send(int pid, char c)
{
	int		i;

	i = 0;
	while (i <= 7)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	int					i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			ft_send(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
		ft_send(ft_atoi(argv[1]), 0);
	}
	return (0);
}
