/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:42:17 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/14 11:49:29 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_error *error, t_data *data)
{
	int	j;

	j = 0;
	printf("Error\n");
	printf("\n");
	if (error->error1 == 1)
		printf("Map is not surrounded by walls.\n");
	if (error->error2 == 1)
		printf("There is no exit\n");
	if (error->error3 == 1)
		printf("There is none or more than one initial position\n");
	if (error->error4 == 1)
		printf("There are no colectables\n");
	if (error->dimensio_err == 1)
		printf("Map dimensions are incorrect\n");
	free (data->map);
	exit (0);
}

void	ft_check2(t_error *error, t_data *data)
{
	if (error->boo == 0)
		error->error2 = 1;
	if (error->boo2 != 1)
		error->error3 = 1;
	if (error->boo3 == 0)
		error->error4 = 1;
	if (error->error1 == 1 || error->error2 == 1
		|| error->error3 == 1 || error->error4 == 1 || error->dimensio_err == 1)
		ft_error(error, data);
}

void	ft_init(t_error *error)
{
	error->boo = 0;
	error->boo2 = 0;
	error->boo3 = 0;
	error->error1 = 0;
	error->error2 = 0;
	error->error3 = 0;
	error->error4 = 0;
	error->dimensio_err = 0;
}

void	ft_check(t_data *data)
{
	int		i;
	int		j;
	t_error	error;
	int		n;

	n = data->max_x;
	j = 0;
	ft_init(&error);
	ft_check4(&error, data);
	while (j < data->max_y)
	{
		i = 0;
		while (i < data->max_x)
		{
			ft_check3(&error, data, j, i);
			i++;
		}
		j++;
	}
	ft_check2(&error, data);
}

void	ft_imput_err(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Input error\n");
		exit (0);
	}
	if (!ft_strrchr(argv[1], '.ber'))
	{
		printf("Input error\n");
		exit (0);
	}
}
