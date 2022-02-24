/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:53:19 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/20 10:59:01 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exademinal(unsigned long int n, int cases, int *len)
{
	char	*base;

	if (cases == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n / 16 > 0)
	{
		ft_exademinal(n / 16, cases, len);
		ft_len_putchar(base[n % 16], len);
	}
	else
		ft_len_putchar(base[n], len);
}

void	ft_len_putnbr(unsigned int n, int *len)
{
	if (n < 10)
		ft_len_putchar(n + '0', len);
	if (n > 9)
	{
		ft_len_putnbr(n / 10, len);
		ft_len_putchar(n % 10 + '0', len);
	}
}

void	ft_len_putnbr2(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_len_putchar('-', len);
		ft_len_putchar('2', len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_len_putchar('-', len);
		n *= (-1);
	}
	if (n < 10)
		ft_len_putchar(n + '0', len);
	if (n > 9)
	{
		ft_len_putnbr(n / 10, len);
		ft_len_putchar(n % 10 + '0', len);
	}
}

void	cases(char c, va_list args, int *len)
{
	if (c == 's')
		ft_len_putstr(va_arg(args, char *), len);
	else if (c == 'c')
		ft_len_putchar(va_arg(args, int), len);
	else if (c == '%')
		ft_len_putchar('%', len);
	else if (c == 'd' || c == 'i')
		ft_len_putnbr2(va_arg(args, int), len);
	else if (c == 'u')
		ft_len_putnbr(va_arg(args, unsigned int), len);
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ft_exademinal(va_arg(args, unsigned long int), 1, len);
		(*len) += 2;
	}
	else if (c == 'x')
		ft_exademinal(va_arg(args, unsigned int), 1, len);
	else if (c == 'X')
		ft_exademinal(va_arg(args, unsigned int), 2, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		j;
	int		len;

	j = 0;
	len = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			cases(str[j + 1], args, &len);
			j += 2;
			continue ;
		}
		ft_len_putchar(str[j], &len);
		j++;
	}
	return (len);
}	
