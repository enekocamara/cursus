/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:32:25 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/08 11:53:57 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
char			*ft_strfinal(char *str);
int				ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *str);
unsigned int	ft_strlcpy(char *dst, const char *src, size_t size);

#endif