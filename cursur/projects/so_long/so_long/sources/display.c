/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:32 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:34:30 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_wallcase4(int x, int y, t_data *data, int n)
{
	char	*path;

	if (data->map[ft_ix(x - 1, y, n)] == '1'
		&& data->map[ft_ix(x, y + 1, n)] == '1')
		path = "obj/top-right.xpm";
	else if (data->map[ft_ix(x - 1, y, n)] == '1'
		&& data->map[ft_ix(x, y - 1, n)] == '1')
		path = "obj/bot-right.xpm";
	else if (data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/right-3.xpm";
	else if (data->map[ft_ix(x + 1, y, n)] == '1')
		path = "obj/left-3.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1')
		path = "obj/top-3.xpm";
	else if (data->map[ft_ix(x, y - 1, n)] == '1')
		path = "obj/bot-3.xpm";
	else
		path = "obj/caja.xpm";
	return (path);
}

char	*ft_wallcase3(int x, int y, t_data *data, int n)
{
	char	*path;

	if (data->map[ft_ix(x, y - 1, n)] == '1' && data->map[ft_ix(x + 1, y,
				n)] == '1' && data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/bot-1.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1' && data->map[ft_ix(x + 1, y,
				n)] == '1' && data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/top-1.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1'
		&& data->map[ft_ix(x, y - 1, n)] == '1')
		path = "obj/left-right.xpm";
	else if (data->map[ft_ix(x + 1, y, n)] == '1'
		&& data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/top-bot.xpm";
	else if (data->map[ft_ix(x + 1, y, n)] == '1'
		&& data->map[ft_ix(x, y + 1, n)] == '1')
		path = "obj/top-left.xpm";
	else if (data->map[ft_ix(x + 1, y, n)] == '1'
		&& data->map[ft_ix(x, y - 1, n)] == '1')
		path = "obj/bot-left.xpm";
	else
		path = ft_wallcase4(x, y, data, n);
	return (path);
}

char	*ft_wallcase2(int x, int y, t_data *data, int n)
{
	char	*path;

	if (x == 0 && data->map[ft_ix(x + 1, y, n)] == '1')
		path = "obj/left-1.xpm";
	else if (x == 0)
		path = "obj/left-right.xpm";
	else if (x == data->max_x - 1 && data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/right-1.xpm";
	else if (x == data->max_x -1)
		path = "obj/left-right.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1'
		&& data->map[ft_ix(x, y - 1, n)] == '1'
		&& data->map[ft_ix(x + 1, y, n)] == '1'
		&& data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/all-0.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1' && data->map[ft_ix(x, y - 1,
				n)] == '1' && data->map[ft_ix(x + 1, y, n)] == '1')
		path = "obj/left-1.xpm";
	else if (data->map[ft_ix(x, y + 1, n)] == '1' && data->map[ft_ix(x, y - 1,
				n)] == '1' && data->map[ft_ix(x - 1, y, n)] == '1')
		path = "obj/right-1.xpm";
	else
		path = ft_wallcase3(x, y, data, n);
	return (path);
}

char	*ft_wallcase(int x, int y, t_data *data)
{
	char	*path;
	int		n;

	n = data->max_x;
	if (y == 0 && x == 0)
		path = "obj/top-left.xpm";
	else if (y == data->max_y - 1 && x == 0)
		path = "obj/bot-left.xpm";
	else if (y == 0 && x == data->max_x - 1)
		path = "obj/top-right.xpm";
	else if (y == data->max_y - 1 && x == data->max_x - 1)
		path = "obj/bot-right.xpm";
	else if (y == 0 && data->map[ft_ix(x, y + 1, n)] == '1')
		path = "obj/top-1.xpm";
	else if (y == 0)
		path = "obj/top-bot.xpm";
	else if (y == data->max_y - 1 && data->map[ft_ix(x, y - 1, n)] == '1')
		path = "obj/bot-1.xpm";
	else if (y == data->max_y - 1)
		path = "obj/top-bot.xpm";
	else
		path = ft_wallcase2(x, y, data, n);
	y = data->x_p;
	return (path);
}
