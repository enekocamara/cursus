/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:40:19 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 13:29:39 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free2str(char **str, int boo)
{
	int	i;

	i = 0;
	if (!boo || str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	ft_freelist(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}
