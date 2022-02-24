/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:44:26 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/15 10:18:50 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//data->max_x + 1 for the \n
void	ft_asset_map(t_data *data)
{
	data->tiles = malloc((data->max_y * data->max_x) * sizeof(void *));
	data->asset_map = ft_strdup(data->map);
}

void	ft_map_read(char *name, t_data *data, int boo)
{
	int		fd;
	int		check;
	char	*temp;
	int		num;

	num = -1;
	fd = open(name, O_RDONLY);
	while (1)
	{
		temp = get_next_line(fd);
		check = ft_strlen(temp);
		if (!temp)
			break ;
		data->check_map = ft_strjoin_sl(&data->check_map, temp, 1, num);
		data->map = ft_strjoin_sl(&data->map, ft_substr_sl(&temp, 0,
					ft_next_line_nl(temp, 0), 0), 1, num);
		if (boo)
		{
			data->max_x = ft_strlen(data->map);
			boo = 0;
		}
		data->max_y++;
		free(temp);
	}
}
