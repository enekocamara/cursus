/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:35:49 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:37:37 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sl(char **s1, char *s2, int boo, int i)
{
	int		j;
	char	*strjoin;

	if (!s2)
		return ((char *)s1);
	j = 0;
	strjoin = (char *) malloc(ft_strlen(*s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (0);
	strjoin[ft_strlen(*s1) + ft_strlen(s2)] = '\0';
	while (++i < ft_strlen(*s1))
	{
		strjoin[j] = (*s1)[i];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		strjoin[j] = s2[i];
		j++;
		i++;
	}
	if (boo)
		free(*s1);
	return (strjoin);
}

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
