/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:18:14 by amara             #+#    #+#             */
/*   Updated: 2021/08/30 11:06:55 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	c;

	if (!dest && !src)
		return (NULL);
	c = 0;
	while (c < n)
	{
		((char *)dest)[c] = ((char *)src)[c];
		c++;
	}
	return (dest);
}
