/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:36:27 by amara             #+#    #+#             */
/*   Updated: 2021/08/20 12:15:34 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	holder;

	c = 0;
	holder = ft_strlen(src);
	if (size != 0)
	{
		while (c < size - 1 && src[c])
		{
			dst[c] = src[c];
			c++;
		}
		if (dst[c])
			dst[c] = '\0';
	}
	return (holder);
}
