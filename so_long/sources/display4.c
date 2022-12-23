/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:51:48 by ecamara           #+#    #+#             */
/*   Updated: 2021/11/24 10:52:27 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dp_bar(t_data *data)
{
	void	*img;
	int		img_p;

	img_p = 50;
	img = mlx_xpm_file_to_image(data->mlx, "obj/bar-2.xpm", &img_p, &img_p);
	mlx_put_image_to_window(data->mlx, data->win, img, 50, 0);
	mlx_put_image_to_window(data->mlx, data->win, img, 100, 0);
	mlx_put_image_to_window(data->mlx, data->win, img, 150, 0);
	mlx_put_image_to_window(data->mlx, data->win, img, 200, 0);
	mlx_put_image_to_window(data->mlx, data->win, img, 250, 0);
	mlx_string_put(data->mlx, data->win, 50, 35, 0x0000FF00, "movements: ");
	mlx_string_put(data->mlx, data->win, 120, 35, 0x0000FF00,
		ft_itoa(data->movement_c));
	mlx_string_put(data->mlx, data->win, 200, 35, 0x0000FF00,
		"colectives: ");
	mlx_string_put(data->mlx, data->win, 280, 35, 0x0000FF00,
		ft_itoa(data->colect));
}

void	ft_bar(t_data *data)
{
	void	*img;
	int		img_p;
	int		i;

	i = 0;
	img_p = 50;
	while (i < data->max_x)
	{
		img = mlx_xpm_file_to_image(data->mlx, "obj/bar-2.xpm", &img_p, &img_p);
		mlx_put_image_to_window(data->mlx, data->win, img, i * 50, 0);
		i++;
	}
}

void	ft_char_st(t_data *data)
{
	int	img_p;

	img_p = 50;
	data->img = mlx_xpm_file_to_image(data->mlx, "obj/ball.xpm",
			&img_p, &img_p);
	mlx_put_image_to_window(data->mlx, data->win, data->img,
		data->x_p * 50, data->y_p * 50 + 50);
}
