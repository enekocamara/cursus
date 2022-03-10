/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:37:15 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 14:28:32 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_best_logic(t_list **head_a, t_list **head_b)
{
	int	pivot;
	int	chunck;

	chunck = 1;
	while (!ft_a_shorted(*head_a) || *head_b != NULL)
	{
		while (ft_chunck_size(head_a) > 2 && !ft_a_shorted(*head_a))
		{
			pivot = ft_index(*head_a);
			ft_pass_a(head_a, head_b, pivot, chunck);
			chunck++;
		}
		ft_2_left_a(head_a);
		if (*head_b != NULL)
		{
			pivot = ft_index(*head_b);
			ft_push_chunck_b(head_a, head_b, pivot);
		}
	}
}

void	ft_push_chunck_b(t_list  **head_a, t_list **head_b, int pivot)
{
	int		rrb;
	int		chunck;
	t_list	*temp;
	int		i;

	temp = *head_b;
	chunck = temp->chunck;
	rrb = 0;
	i = ft_chunck_size(head_b) - ft_chunck_size(head_b) / 2;
	while (i > 0)
	{
		if (temp && (int)temp->content >= pivot)
		{
			i--;
			ft_pa(head_a, head_b);
		}
		else
		{
			ft_rb(head_b, 1);
			rrb++;
		}
		temp = *head_b;
	}
	while (rrb > 0)
	{
		ft_rrb(head_b, 1);
		rrb--;
	}
	if (ft_chunck_size(head_b) <= 2)
		ft_2_left_b(head_a, head_b);
}

static int	ft_pass_a2(t_list **head_a, t_list **head_b, int pivot, int chunck)
{
	t_list	*temp;

	temp = ft_lstlast(*head_a);
	if ((int)temp->content < pivot)
	{
		ft_rra(head_a, 1);
		return (-1);
	}
	temp = *head_a;
	if ((int)temp->content < pivot)
	{
		temp->chunck = chunck;
		ft_pb(head_a, head_b);
		return (-1);
	}
	temp = (*head_a);
	if ((int)temp->content >= pivot)
	{
		ft_ra(head_a, 1);
		return (1);
	}
	return (0);
}

void	ft_pass_a(t_list **head_a, t_list **head_b, int pivot, int chunck)
{
	t_list	*temp;
	int		rra;
	int		num;

	rra = 0;
	while (!ft_check_pivot(*head_a, pivot))
	{
		num = ft_pass_a2(head_a, head_b, pivot, chunck);
		if (num == -1)
			continue ;
		rra += num;
	}
	while (rra > 0)
	{
		temp = ft_lstlast(*head_a);
		if ((int)temp->chunck == 0)
			return ;
		ft_rra(head_a, 1);
		rra--;
	}
}
