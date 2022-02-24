/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:24:30 by amara             #+#    #+#             */
/*   Updated: 2021/08/16 11:47:40 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	c;

	c = 0;
	while (c < n)
	{
		if (((unsigned char *)str1)[c] != ((unsigned char *)str2)[c])
			return (((unsigned char *)str1)[c] - ((unsigned char *)str2)[c]);
		c++;
	}
	return (0);
}
