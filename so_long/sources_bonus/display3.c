/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:50:39 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/14 09:54:57 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_tile_case4(t_data *data, int x, int y, int n)
{
	int	num;
	int	p;

	p = 50;
	num = ft_random_num(1, 100);
	if (num >= 66 && num <= 70)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-6.xpm", &p, &p);
	else if (num >= 71 && num <= 75)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-7.xpm", &p, &p);
	else
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-3.xpm", &p, &p);
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(x, y, n)],
		x * 50, y * 50 + 50);
}

void	ft_tile_case3(t_data *data, int x, int y, int n)
{
	int	num;
	int	p;

	p = 50;
	num = ft_random_num(1, 100);
	if (num >= 46 && num <= 50)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-2.xpm", &p, &p);
	else if (num >= 51 && num <= 55)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-3.xpm", &p, &p);
	else if (num >= 56 && num <= 60)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-4.xpm", &p, &p);
	else if (num >= 61 && num <= 65)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-5.xpm", &p, &p);
	else
	{
		ft_tile_case4(data, x, y, n);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(x, y, n)],
		x * 50, y * 50 + 50);
}

void	ft_tile_case2(t_data *data, int x, int y, int n)
{
	int	num;
	int	p;

	p = 50;
	num = ft_random_num(1, 100);
	if (num >= 26 && num <= 30)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-5.xpm", &p, &p);
	else if (num >= 31 && num <= 35)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-6.xpm", &p, &p);
	else if (num >= 36 && num <= 40)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-7.xpm", &p, &p);
	else if (num >= 41 && num <= 45)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/tile-1.xpm", &p, &p);
	else
	{
		ft_tile_case3(data, x, y, n);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(x, y, n)],
		x * 50, y * 50 + 50);
}

void	ft_tile_case(t_data *data, int x, int y, int n)
{
	int	num;
	int	p;

	p = 50;
	num = ft_random_num(1, 100);
	if (num >= 1 && num <= 10)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-1.xpm", &p, &p);
	else if (num >= 11 && num <= 15)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-2.xpm", &p, &p);
	else if (num >= 16 && num <= 20)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-3.xpm", &p, &p);
	else if (num >= 21 && num <= 25)
		data->tiles[ft_ix(x, y, n)] = mlx_xpm_file_to_image(data->mlx,
				"obj/grass-4.xpm", &p, &p);
	else
	{
		ft_tile_case2(data, x, y, n);
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->tiles[ft_ix(x, y, n)],
		x * 50, y * 50 + 50);
}
