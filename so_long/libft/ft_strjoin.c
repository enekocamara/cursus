/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:28:39 by ecamara           #+#    #+#             */
/*   Updated: 2021/10/27 16:06:39 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	char	*strjoin;

	if (!s1)
		return (0);
	if (!s2)
		return ((char *)s1);
	j = 0;
	strjoin = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (0);
	strjoin[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (*s1)
	{
		strjoin[j] = *s1++;
		j++;
	}
	while (*s2)
	{
		strjoin[j] = *s2++;
		j++;
	}
	return (strjoin);
}
