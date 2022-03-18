/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:37:59 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/11 13:06:59 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_2_left_b(t_list **head_a, t_list **head_b)
{
	t_list	*temp_b;

	temp_b = *head_b;
	if (!temp_b || ft_chunck_size(head_b) == 1)
		return ;
	else
	{
		if ((int)temp_b->content < (int)temp_b->next->content)
			ft_sb(*head_b, 1);
		ft_pa(head_a, head_b);
		ft_pa(head_a, head_b);
	}
}

void	ft_2_left_a(t_list **head_a)
{
	t_list	*temp;

	temp = *head_a;
	if (ft_chunck_size(head_a) == 2)
	{
		if ((int)temp->content > (int)temp->next->content)
			ft_sa(*head_a, 1);
	}
}

int	ft_a_shorted(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;

	temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp2 = temp->next;
		while (temp2 != NULL)
		{
			if ((int)temp->content > (int)temp2->content)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

void	ft_case3(t_list **head)
{
	t_list	*temp;

	if (!ft_a_shorted(*head))
	{
		temp = *head;
		if ((int)temp->content > (int)temp->next->next->content
			&& (int)temp->content > (int)temp->next->content)
			ft_ra(head, 1);
		else if ((int)temp->next->content > (int)temp->content
			&& (int)temp->next->content > (int)temp->next->next->content)
			ft_rra(head, 1);
		temp = *head;
		if ((int)temp->content > (int)temp->next->content)
			ft_sa(*head, 1);
	}
}
