/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:35:54 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 13:30:46 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *head, int boo)
{
	void	*temp;
	t_list	*ptr;

	temp = head->content;
	ptr = head->next;
	head->content = ptr->content;
	ptr->content = temp;
	if (boo)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list *head, int boo)
{
	void	*temp;
	t_list	*ptr;

	temp = head->content;
	ptr = head->next;
	head->content = ptr->content;
	ptr->content = temp;
	if (boo)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list *head_a, t_list *head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list	*ptr;

	ptr = *head_b;
	*head_b = ptr->next;
	ft_lstadd_front(head_a, ptr);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list	*ptr;

	ptr = *head_a;
	*head_a = ptr->next;
	ft_lstadd_front(head_b, ptr);
	write(1, "pb\n", 3);
}
