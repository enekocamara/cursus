/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:41:24 by ecamara           #+#    #+#             */
/*   Updated: 2021/12/14 12:11:49 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check3(t_error *error, t_data *data, int j, int i)
{
	if (data->map[ft_ix(i, j, data->max_x)] != '1' && (j == 0 || j
			== data->max_y - 1 || i == 0 || data->max_x - 1 == i))
		error->error1 = 1;
	if (data->map[ft_ix(i, j, data->max_x)] == 'E')
		error->boo = 1;
	if (data->map[ft_ix(i, j, data->max_x)] == 'P')
		error->boo2++;
	if (data->map[ft_ix(i, j, data->max_x)] == 'C')
		error->boo3++;
}

void	ft_check4(t_error *error, t_data *data)
{
	int	len;
	int	i;
	int	len2;
	int	boo;

	i = 0;
	len = 0;
	len2 = 0;
	boo = 0;
	while (1)
	{
		if (ft_next_line_nl(data->check_map + i, 0) != len && boo)
		{
			error->dimensio_err = 1;
			break ;
		}
		len = ft_next_line_nl(data->check_map + i, 0);
		i = i + len + 1;
		if (data->check_map[i - 1] == '\0')
			break ;
		boo = 1;
	}
}
