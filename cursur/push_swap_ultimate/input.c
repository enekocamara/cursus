/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:43:16 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/17 10:56:42 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_short(t_data *data)
{
	
}

void	fill_list(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->size)
	{
		data->list[j][0] = atoi(str[j]);
	}
}

void	ft_input(char **str, t_data *data)
{
	int	**temp;
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	data->list = calloc(i, sizeof(int *));
	data->size = i;
	i = 0;
	while (str[i] != NULL)
	{
		data->list[i] = malloc(7, sizeof(int));
		data->list[j][0] = atoi(str[j]);
		i++;
	}
	fill_list(data);
}
