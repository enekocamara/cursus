/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:53:33 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/18 12:40:19 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr_sl(char **s, int start, int len, int w)
{
	int		c;
	char	*substr;

	c = -1;
	if (!(*s) && len == 0)
		return (NULL);
	if (ft_strlen(*s) < start)
	{
		substr = (char *)malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	else
		substr = (char *) malloc(len + 1);
	if (!substr)
		return (0);
	substr[len] = '\0';
	while (++c < len)
		substr[c] = (*s)[c + start];
	if (w == 1)
		ft_strdel(s);
	return (substr);
}

int	ft_next_line_sl(char *temp, int j)
{
	int	i;

	i = 0;
	if (!temp || !*temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	if (j == 1)
		return (0);
	i++;
	return (i);
}

int	ft_line(char *map)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int	ft_random_num(int start, int end)
{
	static int	num = 0xACE1U;

	num += 0x3AD;
	num %= end;
	while (num < start)
		num = num + end - start;
	return (num);
}

int	ft_ix(int i, int j, int n)
{
	return (i + j * n);
}
