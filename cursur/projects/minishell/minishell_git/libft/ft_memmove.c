/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:24:22 by amara             #+#    #+#             */
/*   Updated: 2021/08/20 12:04:50 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	c;

	c = 0;
	if (!dest && !src)
		return (NULL);
	if (src > dest)
	{
		while (c < n)
		{
			((char *)dest)[c] = ((char *)src)[c];
			c++;
		}
	}
	else
	{
		while (c < n)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
