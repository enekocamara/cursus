/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:07:29 by amara             #+#    #+#             */
/*   Updated: 2022/02/07 11:05:40 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(str1) == 0 && ft_strlen(str2) == 0)
		return (0);
	while (c < n - 1 && str1[c] != '\0' && str2[c] != '\0')
	{
		if (str1[c] != str2[c])
			return ((unsigned char)str1[c] - (unsigned char)str2[c]);
		c++;
	}
	return ((unsigned char)str1[c] - (unsigned char)str2[c]);
}
