/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:46:24 by amara             #+#    #+#             */
/*   Updated: 2021/09/10 09:45:22 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	e;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (size > i && size > 0)
	{
		e = i + j;
		j = 0;
		size = size - 1 - i;
		while (src[j] && size != 0)
		{
			dst[i++] = src[j++];
			size--;
		}
		dst[i] = '\0';
	}
	else
	{
		e = size + j;
	}
	return (e);
}
