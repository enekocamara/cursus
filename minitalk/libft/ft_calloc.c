/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:01:45 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/23 09:37:29 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*voidptr;

	voidptr = (void *)malloc(size * nitems);
	if (!voidptr)
		return (NULL);
	ft_memset(voidptr, 0, size * nitems);
	return (voidptr);
}
