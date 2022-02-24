/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 09:26:07 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/03 13:19:31 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_line(char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*strsplit(char **temp, char **final)
{
	char	*temp2;
	int		i;

	i = 0;
	while ((*temp)[i] != '\n')
	{
		(*final)[i] = (*temp)[i];
		i++;
	}
	(*final)[++i] = '\n';
	(*final)[i + 1] = '\0';
	if ((*temp)[i])
		temp2 = ft_strdup((*temp) + i);
	//printf("split direction: %p", temp2);
	*temp = ft_strdup(temp2);
	return (*final);
}

char	*process_data(char **temp)
{
	char	*final;

	if (!next_line(*temp))
	{
		final = ft_strdup(*temp);
		free (*temp);
		return (final);
	}
	final = malloc(ft_strlen(*temp) + 1);
	return (strsplit(temp, &final));
}

int	case1(int fd, char **temp)
{
	int		i;
	char	*buffer;

	if (!next_line(*temp))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0 && !*temp)
		{
			free (buffer);
			return (1);
		}
		else if (i == 0 && *temp)
		{
			free (buffer);
			return (0);
		}
		*temp = ft_strjoin(*temp, buffer);
		//printf("temp: [%s]\n buffer: [%s]\n", *temp, buffer);
		if (next_line(*temp))
			return (2);
		case1(fd, temp);
	}
	return (2);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	int			i;
	char		*final;

	i = 1;
	//printf("entrada");
	if (fd == 0)
		return (0);
	i = case1(fd, &temp);
	//printf("final temp: %s", temp);
	if (i == 1)
		return (NULL);
	else if (i == 2)
		final = process_data(&temp);
	return (final);
}
