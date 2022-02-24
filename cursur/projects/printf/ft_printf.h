/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:17:42 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/20 10:56:43 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_len_putchar(char c, int *len);
void	ft_len_putstr(char *str, int *len);
void	ft_exademinal(unsigned long int n, int cases, int *len);
void	ft_len_putnbr(unsigned int n, int *len);
void	ft_len_putnbr2(int n, int *len);
void	cases(char c, va_list args, int *len);

#endif
