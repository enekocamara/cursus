/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:51:57 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/14 13:02:17 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	freeo(char **list)
{
	while (*list)
	{
		free (*list);
		(*list)++;
	}
	free (list);
	return (0);
}

unsigned int	count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c && j == 0)
		{
			i++;
			j = 1;
		}
		else if (*s == c)
			j = 0;
		s++;
	}
	return (i);
}

char	**str(const char *str, unsigned int j, char c, char **list)
{
	unsigned int	i;
	unsigned int	index;
	int				r;

	i = 0 ;
	r = 0;
	while (j < count(str, c))
	{
		if (str[i] != c && r == 0)
		{
			index = i;
			r = 1;
		}
		else if ((str[i] == c || str[i] == '\0') && r == 1)
		{
			list[j] = ft_substr(str, index, (i - index));
			if (!list[j])
				freeo(list);
			r = 0;
			j++;
		}
		i++;
	}
	list[j] = 0;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	long int		i;
	unsigned int	j;
	char			**list;

	j = 0;
	if (!s)
		return (NULL);
	else
	{
		i = count(s, c);
		list = (char **)malloc(sizeof(char *) * (i + 1));
		if (!list)
			return (NULL);
	}
	return (str(s, j, c, list));
}
