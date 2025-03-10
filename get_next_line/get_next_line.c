/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:19:43 by ecamara           #+#    #+#             */
/*   Updated: 2022/01/27 10:07:15 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_line(char *temp, int j)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	if (j == 1)
		return (0);
	return (i);
}

char	*join(char **s1, char **s2, int lens1, int lens2)
{
	int		j;
	char	*strjoin;
	int		i;

	j = 0;
	strjoin = (char *)malloc(lens1 + lens2 + 1);
	if (!strjoin)
		return (NULL);
	strjoin[lens1 + lens2] = '\0';
	while (j < lens1)
	{
		strjoin[j] = (*s1)[j];
		j++;
	}
	i = j;
	while ((j - i) < lens2)
	{
		strjoin[j] = (*s2)[j - i];
		j++;
	}
	ft_strdel(s1);
	ft_strdel(s2);
	return (strjoin);
}

char	*ft_substr(char **s, int start, int len, int w)
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

char	*ft_read(char **temp, int fd)
{
	int			i;
	char		*buffer;

	i = 1;
	while (!next_line(*temp, 1) && i != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || (i == 0 && !(*temp)) || (i == 0 && (*temp)[0] == '\0'))
		{
			free (buffer);
			ft_strdel(temp);
			return (NULL);
		}
		buffer[i] = '\0';
		*temp = join(temp, &buffer, ft_strlen(*temp), ft_strlen(buffer));
	}
	return (*temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	char		*final;
	int			end;

	temp = ft_read(&temp, fd);
	if (!temp)
		return (NULL);
	buffer = ft_substr(&temp, 0, next_line(temp, 0) + 1, 0);
	end = ft_strlen(temp + next_line(temp, 0) + 1);
	final = ft_substr(&temp, next_line(temp, 0) + 1, end, 1);
	ft_strdel(&temp);
	temp = join(&temp, &final, ft_strlen(temp), ft_strlen(final));
	return (buffer);
}
