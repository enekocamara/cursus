/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:38:54 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 14:30:06 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_pivot(t_list *head, int pivot)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if ((int)temp->content < pivot)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_chunck_b_pushed(t_list *head, int chunck)
{
	t_list	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->chunck == chunck)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_index(t_list *head)
{
	int		*nums;
	int		len;
	t_list	*temp;
	int		chunck;

	len = 0;
	temp = head;
	chunck = temp->chunck;
	while (temp != NULL && chunck == (int)temp->chunck)
	{
		len++;
		temp = temp->next;
	}
	temp = head;
	nums = malloc(4 * (len));
	len = 0;
	while (temp != NULL && chunck == (int)temp->chunck)
	{
		nums[len] = (int)temp->content;
		temp = temp->next;
		len++;
	}
	return (ft_quick_short(&nums, len));
}

int	ft_quick_short(int **nums, int len)
{
	int	i;
	int	j;
	int	temp;
	int	mid;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len - 1)
		{
			if ((*nums)[i] > (*nums)[i + 1])
			{
				temp = (*nums)[i];
				(*nums)[i] = (*nums)[i + 1];
				(*nums)[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
	mid = (*nums)[len / 2];
	free (*nums);
	return (mid);
}

int	ft_chunck_size(t_list **head)
{
	t_list	*temp;
	int		chunck;
	int		i;

	i = 0;
	temp = *head;
	if (!temp)
		return (0);
	chunck = (int)temp->chunck;
	while (temp != NULL && chunck == (int)temp->chunck)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
