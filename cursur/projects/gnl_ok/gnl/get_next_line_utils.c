/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:32:33 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/03 13:22:40 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s)
{
	unsigned int	i;
	char			*substr;
	unsigned int	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n')
		i++;
	substr = malloc(ft_strlen(s) - i);
	substr[ft_strlen(s) - i - 1] = '\0';
	i++;
	j = i;
	while (s[i - j] != '\0')
	{
		substr[i - j] = s[i];
		i++;
	}
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	unsigned int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	//printf("len %d", c);
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*strjoin;

	j = 0;
	strjoin = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (0);
	strjoin[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (j < ft_strlen(s1))
	{
		strjoin[j] = s1[j];
		j++;
	}
	i = j;
	while (s2[j - i])
	{
		strjoin[j] = s2[j - i];
		j++;
	}
	free (s1);
	free (s2);
	return (strjoin);
}

unsigned int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	holder;

	c = 0;
	holder = ft_strlen(src);
	if (size != 0)
	{
		while (c < size - 1 && src[c])
		{
			dst[c] = src[c];
			c++;
		}
		if (dst[c])
			dst[c] = '\0';
	}
	return (holder);
}

char	*ft_strdup(const char *str)
{
	unsigned int	c;
	char			*dupstr;

	c = ft_strlen(str);
	dupstr = (char *)malloc(c + 1);
	if (!dupstr)
		return (0);
	ft_strlcpy(dupstr, str, c + 1);
	return (dupstr);
}
