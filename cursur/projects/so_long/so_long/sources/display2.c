/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:48:38 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:34:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cases(t_data *data, int x, int y, void *img)
{
	int		p;

	p = 50;
	if (data->map[ft_ix(x, y, data->max_x)] == '1')
	{
		img = mlx_xpm_file_to_image(data->mlx, ft_wallcase(x, y, data), &p, &p);
		mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50 + 50);
	}
	if (data->map[ft_ix(x, y, data->max_x)] == 'E')
	{
		img = mlx_xpm_file_to_image(data->mlx, "obj/portal-2.xpm", &p, &p);
		mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50 + 50);
	}
	if (data->map[ft_ix(x, y, data->max_x)] == 'P')
	{
		data->x_p = x;
		data->y_p = y;
		ft_char_st(data);
	}
	if (data->map[ft_ix(x, y, data->max_x)] == 'C')
	{
		img = mlx_xpm_file_to_image(data->mlx, "obj/coleccionable.xpm", &p, &p);
		mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50 + 50);
		data->colect++;
	}
}

void	ft_dp_map(t_data *data)
{
	int		img_p;
	void	*img;
	int		x;
	int		y;

	img = NULL;
	img_p = 50;
	y = 0;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			ft_tile_case(data, x, y, data->max_x);
			ft_cases(data, x, y, img);
			x++;
		}
		y++;
	}
	ft_bar(data);
}

void	ft_frame2(t_data *data, int x, int y)
{
	int		p;
	void	*img;

	p = 50;
	if (data->colect == 0 && data->asset_map[ft_ix(x, y, data->max_x)] == 'E')
	{
		img = mlx_xpm_file_to_image(data->mlx, "obj/portal-1.xpm", &p, &p);
		mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50 + 50);
	}
	else if (data->asset_map[ft_ix(x, y, data->max_x)] == 'c')
	{
		img = mlx_xpm_file_to_image(data->mlx,
				"obj/coleccionable-2.xpm", &p, &p);
		mlx_put_image_to_window(data->mlx, data->win, img, x * 50, y * 50 + 50);
	}
}

void	ft_frame(t_data *data)
{
	int		img_p;
	int		x;
	int		y;

	y = 0;
	img_p = 50;
	while (y < data->max_y)
	{
		x = 0;
		while (x < data->max_x)
		{
			ft_frame2(data, x, y);
			x++;
		}
		y++;
	}
	ft_dp_bar(data);
}
