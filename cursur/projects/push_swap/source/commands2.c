/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:36:05 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/09 13:44:20 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **head, int boo)
{
	t_list	*temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (boo)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **head, int boo)
{
	t_list	*temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (boo)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	ft_ra(head_a, 0);
	ft_rb(head_b, 0);
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **head, int boo)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *head;
	temp = *head;
	while (ptr != NULL && ptr->next != NULL)
		ptr = ptr->next;
	while (temp != NULL && temp->next != ptr)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(head, ptr);
	if (boo)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **head, int boo)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = *head;
	temp = *head;
	if (temp->next == NULL)
		return ;
	while (ptr != NULL && ptr->next != NULL)
		ptr = ptr->next;
	while (temp != NULL && temp->next != ptr)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(head, ptr);
	if (boo)
		write(1, "rrb\n", 4);
}
