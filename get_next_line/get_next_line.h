/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:17:35 by ecamara           #+#    #+#             */
/*   Updated: 2021/09/29 09:55:07 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char			*get_next_line(int fd);
void			ft_strdel(char **as);
int				ft_strlen(const char *str);
int				next_line(char *temp, int j);
char			*join(char **s1, char **s2, int lens1, int lens2);
char			*ft_substr(char **s, int start, int len, int w);
char			*ft_read(char **temp, int fd);

#endif