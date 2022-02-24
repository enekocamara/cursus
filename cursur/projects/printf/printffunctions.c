/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printffunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:52:55 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/20 10:56:46 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_len_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_len_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		*len += write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		ft_len_putchar(str[i], len);
		i++;
	}
}
