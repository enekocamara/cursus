/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 09:44:45 by ecamara           #+#    #+#             */
/*   Updated: 2023/01/16 13:06:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int	ft_strlen(const char *str)
{
	unsigned int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
