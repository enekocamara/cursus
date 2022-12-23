/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:24:37 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/19 12:34:52 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_findchr(const char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (((char *)str)[i] != c || ((char *)str)[i] != '\0')
		i++;
	return (i);
}
