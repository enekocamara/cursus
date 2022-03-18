/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:34:34 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/11 13:32:04 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(const char *str)
{
	int					c;
	int					i;
	unsigned long int	num;

	c = 0;
	i = 1;
	num = 0;
	while (str[c] && (str[c] == ' ' || (str[c] <= 13 && str[c] >= 9)))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			i *= -1;
		c++;
	}
	while (str[c] <= '9' && str[c] >= '0' && str[c] != '\0')
	{
		num = (num * 10) + (str[c] - '0');
		c++;
	}
	if (num > 2147483647 && i == 1)
		ft_error();
	if (num > 2147483648 && i == -1)
		ft_error();
	return (num * i);
}

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
	ft_check_before(str, boo);
	while (str[i] != NULL)
	{
		num = ft_atoi_ps(str[i]);
		ft_lstadd_back(head_a, ft_lstnew_ps(num));
		i++;
	}
	temp = *head_a;
	while (temp != NULL)
	{
		temp->chunck = 0;
		temp = temp->next;
	}
	if (boo == 1)
		ft_free2str(str, boo);
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
