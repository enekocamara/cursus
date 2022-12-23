/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:24:18 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:45:12 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

void	sighandler(int signal, siginfo_t *a, void *b)
{
	static char	bi;
	static int	j;

	(void) b;
	if (!j)
	{
		j = 0;
		bi = 0;
	}
	if (signal == 30)
		bi += (0x01 << j);
	if (j == 7)
	{
		if (bi == 0)
		{
			usleep(1000);
			write(1, "\n", 1);
			kill(a->si_pid, SIGUSR1);
		}
		else
			write(1, &bi, 1);
		j = -1;
		bi = 0;
	}
	j++;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sighandler;
	printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause ();
	}
	return (0);
}
