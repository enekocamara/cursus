/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:25:17 by ecamara           #+#    #+#             */
/*   Updated: 2022/02/11 17:14:48 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp_sh(const char *str1, const char *str2, size_t n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (0);
	if (ft_strlen(str1) == 0 || ft_strlen(str2) == 0)
		return (0);
	while (c < n - 1 && str1[c] != '\0' && str2[c] != '\0')//c < n -1
	{
	//	printf("str1 = [%c]    str2 = [%c]\n", str1[c], str2[c]);
		if (str1[c] != str2[c])
		{
			//printf("Is not the same\n\n");
			return (0);
		}
		c++;
	}
	//printf("\n");
	if (c != n - 1)
	{
		//printf("Is not the same\n\n");
		return (0);
	}
	return (1);
}

char	**ft_copy_2d(char **str)
{
	int		c;
	char	**env;

	c = 0;
	if (!str)
		return (0);
	while (str[c])
	{
		c++;
	}
	env = (char **)malloc(sizeof(char *) * (c + 1));
	env[c] = NULL;
	c = 0;
	while (str[c])
	{
		env[c] = ft_strdup(str[c]);
		c++;
	}
	return (env);
}

void	ft_superprintf(char **str)
{
	int	c;

	c = 0;
	if (!str || !str[0])
		return ;
	while (str[c])
	{
		printf("[%s]\n", str[c]);
		c++;
	}
}

char	*ft_index(char **str)
{
	int		c;
	char	*final;

	if (!*str)
		return (0);
	c = 0;
	while ((*str)[c] && (*str)[c] == ' ')
		c++;
	final = ft_strdup(*str + c);
	free (*str);
	return (final);
}

void	ft_superfree(char **str)
{
	int	c;

	c = 0;
	while (str[c] != NULL)
	{
		free(str[c]);
		c++;
	}
	free(str);
}

void	ft_putstr(char *s)
{
	if (s)
		write (2, (const char *)s, ft_strlen(s));
	else
		write(2, "(null)", 6);
}

