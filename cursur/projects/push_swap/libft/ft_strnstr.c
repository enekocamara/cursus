/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:28:54 by amara             #+#    #+#             */
/*   Updated: 2021/08/17 11:47:51 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	c;
	unsigned int	i;

	c = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (c < n && haystack[c] != '\0')
	{
		i = 0;
		while (haystack[c + i] && needle[i] && c + i < n
			&& haystack[c + i] == needle[i])
			i++;
		if (!needle[i])
			return ((char *)haystack + c);
		c++;
	}
	return (NULL);
}
