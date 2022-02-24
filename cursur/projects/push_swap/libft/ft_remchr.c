/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:10:05 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/19 10:11:43 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remchr(char *str, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (str[i + start])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}
