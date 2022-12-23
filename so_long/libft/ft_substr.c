/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:22:37 by ecamara           #+#    #+#             */
/*   Updated: 2021/10/27 13:36:23 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*substr;

	c = -1;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (int)start)
	{
		substr = (char *)malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (ft_strlen(s + start) < (int)len)
	{
		substr = (char *) malloc(ft_strlen(s + start) + 1);
		len = ft_strlen(s + start);
	}
	else
		substr = (char *) malloc(len + 1);
	if (!substr)
		return (0);
	substr[len] = '\0';
	while (++c < len)
		substr[c] = s[c + start];
	return (substr);
}
