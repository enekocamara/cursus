/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:04:37 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:35:10 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void	ft_enemy_spawn(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->max_y)
	{
		i = 0;
		while (i < data->max_x - 1)
		{
			if (data->asset_map[ft_ix(i, j, data->max_x)] == 'Z')
				data->asset_map[ft_ix(i, j, data->max_x)] = '0';
			if (data->asset_map[ft_ix(i, j, data->max_x)] == 'X')
				data->asset_map[ft_ix(i, j, data->max_x)] = 'Z';
			if (data->asset_map[ft_ix(i, j, data->max_x)] == 'x')
				data->asset_map[ft_ix(i, j, data->max_x)] = 'X';
			if (data->asset_map[ft_ix(i, j, data->max_x)] == 'z')
				data->asset_map[ft_ix(i, j, data->max_x)] = 'x';
			if (data->asset_map[ft_ix(i, j, data->max_x)] == '0'
				&& ft_random_num(1, 100) < 20)
				data->asset_map[ft_ix(i, j, data->max_x)] = 'z';
			i++;
		}
		j++;
	}
}*/

void	ft_reaction(t_data *data)
{
	if (data->asset_map[ft_ix(data->x_p, data->y_p, data->max_x)] == 'C')
	{
		data->asset_map[ft_ix(data->x_p, data->y_p, data->max_x)] = 'c';
		data->colect--;
	}
	if (data->asset_map[ft_ix(data->x_p, data->y_p, data->max_x)]
		== 'E' && data->colect == 0)
	{
		printf("\nWinner\nFinal number of movements: %d", data->movement_c);
		ft_close(data);
	}
}

int	ft_events3(int keycode, t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = data->max_x;
	if (keycode == 1 && data->map[ft_ix(data->x_p, data->y_p + 1, n)] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(
				data->x_p, data->y_p, n)], data->x_p * 50, data->y_p * 50 + 50);
		data->map[ft_ix(data->x_p, data->y_p, n)] = '0';
		data->y_p++;
		data->map[ft_ix(data->x_p, data->y_p, data->max_x)] = 'P';
		i = 1;
	}
	else if (keycode == 2 && data->map[ft_ix(data->x_p + 1,
				data->y_p, n)] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(
				data->x_p, data->y_p, n)], data->x_p * 50, data->y_p * 50 + 50);
		data->map[ft_ix(data->x_p, data->y_p, data->max_x)] = '0';
		data->x_p++;
		data->map[ft_ix(data->x_p, data->y_p, data->max_x)] = 'P';
		i = 1;
	}
	return (i);
}

int	ft_events2(int keycode, t_data *data, int n)
{
	int	i;

	i = 0;
	if (keycode == 13 && data->map[ft_ix(data->x_p, data->y_p - 1, n)] != '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(
				data->x_p, data->y_p, n)], data->x_p * 50, data->y_p * 50 + 50);
		data->map[ft_ix(data->x_p, data->y_p, n)] = '0';
		data->y_p--;
		data->map[ft_ix(data->x_p, data->y_p, n)] = 'P';
		i = 1;
	}
	else if (keycode == 0 && data->map[ft_ix(data->x_p - 1, data->y_p, n)]
		!= '1')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(
				data->x_p, data->y_p, n)], data->x_p * 50, data->y_p * 50 + 50);
		data->map[ft_ix(data->x_p, data->y_p, n)] = '0';
		data->x_p--;
		data->map[ft_ix(data->x_p, data->y_p, n)] = 'P';
		i = 1;
	}
	else
		i = ft_events3(keycode, data);
	return (i);
}

int	ft_events(int keycode, t_data *data)
{
	int	i;

	i = 0;
	if (keycode == 53)
		exit (0);
	i = ft_events2(keycode, data, data->max_x);
	if (i == 1)
	{
		ft_frame(data);
		ft_char_st(data);
		ft_reaction(data);
		data->movement_c++;
		printf("number of movements: %d\n", data->movement_c);
	}
	keycode++;
	(void)data;
	return (0);
}
