/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:06:27 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/17 12:23:48 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
