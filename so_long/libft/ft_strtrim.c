/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:38:38 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/02 17:53:18 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	char			*s2;
	int				j;

	i = 0;
	if (!set || !s1)
		return (0);
	j = ft_strlen(s1);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			break ;
	}
	while (j > i)
	{
		if (ft_strchr(set, s1[j - 1]))
			j--;
		else
			break ;
	}
	s2 = ft_substr(s1, i, j - i);
	return (s2);
}
