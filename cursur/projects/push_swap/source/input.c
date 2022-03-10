/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:34:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 12:58:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_ps(size_t content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = (void *)content;
	node->next = NULL;
	return (node);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	(void) str;
	if (!str)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1]
		&& (str[i + 1] < '0' || str[i + 1] > '9'))
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_create_list(t_list **head_a, char **str, int boo)
{
	int		i;
	int		num;
	t_list	*temp;

	i = 0;
	while (str[i] != NULL)
	{
		if (!ft_check(str[i]))
		{
			ft_free2str(str, boo);
			ft_freelist(*head_a);
			ft_error();
		}
		num = ft_atoi(str[i]);
		ft_lstadd_back(head_a, ft_lstnew_ps(num));
		i++;
	}
	ft_free2str(str, boo);
	temp = *head_a;
	while (temp != NULL)
	{
		temp->chunck = 0;
		temp = temp->next;
	}
}

int	ft_check_repeat(t_list *head)
{
	t_list	*temp;

	while (head != NULL)
	{
		temp = head->next;
		while (temp != NULL)
		{
			if ((int)temp->content == (int)head->content)
				return (1);
			temp = temp->next;
		}
		head = head->next;
	}
	return (0);
}
