/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:07:36 by ecamara           #+#    #+#             */
/*   Updated: 2021/08/30 12:42:21 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!(*lst))
		return ;
	while ((*lst))
	{
		temp = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		(*lst) = temp;
	}
	lst = NULL;
}
