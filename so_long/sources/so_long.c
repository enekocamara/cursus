/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:42:00 by ecamara           #+#    #+#             */
/*   Updated: 2022/02/08 15:17:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	data.max_y = 0;
	data.mlx = mlx_init();
	data.movement_c = 0;
	ft_imput_err(argc, argv);
	ft_map_read(argv[1], &data, 1);
	ft_check(&data);
	ft_asset_map(&data);
	data.win = mlx_new_window(data.mlx, data.max_x * 50,
			data.max_y * 50 + 50, "GAME");
	ft_dp_map(&data);
	mlx_hook(data.win, 2, 1L << 0, ft_events, &data);
	mlx_hook(data.win, 17, 1L << 5, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
