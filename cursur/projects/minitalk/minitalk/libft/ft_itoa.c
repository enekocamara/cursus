/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 10:28:08 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/30 11:06:54 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigit(long n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		nb = 1;
		n *= (-1);
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	unsigned int	i;
	char			*str;
	unsigned int	nb;
	long int		minint;

	minint = (int long) n;
	i = ft_countdigit(minint);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	nb = 0;
	if (minint < 0)
	{
		str[0] = '-';
		nb = 1;
		minint *= -1;
	}
	while (--i > nb)
	{
		str[i] = (minint % 10) + '0';
		minint /= 10;
	}
	str[i] = minint + '0';
	return (str);
}
