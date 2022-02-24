/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:17:50 by ecamara           #+#    #+#             */
/*   Updated: 2022/02/03 11:37:12 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_list *head_a, t_list *head_b)
{
	printf("\nchuck a: ");
	while (head_a != NULL)
	{
		printf("%d c[%d] ", (int)head_a->content, (int)head_a->chunck);
		head_a = head_a->next;
	}
	printf("\nchuck b: ");
	while (head_b != NULL)
	{
		printf("%d c[%d] ", (int)head_b->content, (int)head_b->chunck);
		head_b = head_b->next;
	}
	printf("\n");
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
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] && (str[i + 1] < '0' || str[i + 1] > '9'))
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

void	ft_create_list(t_list **head_a, char **str)
{
	int		i;
	int		num;
	t_list	*temp;

	i = 0;
	while (str[i] != NULL)
	{
		if (!ft_check(str[i]))
			exit(0);
		num = ft_atoi(str[i]);
		ft_lstadd_back(head_a, ft_lstnew_ps(num));
		i++;
	}
	temp = *head_a;
	while (temp != NULL)
	{
		temp->chunck = 0;
		temp = temp->next;
	}
}

void	ft_sa(t_list *head, int boo)
{
	void	*temp;
	t_list *ptr;

	temp = head->content;
	ptr = head->next;
	head->content = ptr->content;
	ptr->content = temp;
	if (boo)
		printf("sa\n");
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
		printf("sb\n");
}

void	ft_ss(t_list *head_a, t_list *head_b)
{
	ft_sa(head_a, 0);
	ft_sb(head_b, 0);
	printf("ss\n");
}

void	ft_pa(t_list **head_a, t_list **head_b)
{
	t_list *ptr;

	ptr = *head_b;
	*head_b = ptr->next;
	ft_lstadd_front(head_a, ptr);
	printf("pa\n");
}

void	ft_pb(t_list **head_a, t_list **head_b)
{
	t_list *ptr;

	ptr = *head_a;
	*head_a = ptr->next;
	ft_lstadd_front(head_b, ptr);
	printf("pb\n");
}

void	ft_ra(t_list **head, int boo)
{
	t_list *temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (boo)
		printf("ra\n");
}

void	ft_rb(t_list **head, int boo)
{
	t_list *temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	ft_lstadd_back(head, temp);
	if (boo)
		printf("rb\n");
}

void	ft_rr(t_list **head_a, t_list **head_b)
{
	ft_ra(head_a, 0);
	ft_rb(head_b, 0);
	printf("rr\n");
}

void	ft_rra(t_list **head, int boo)
{
	t_list *ptr;
	t_list *temp;

	ptr = *head;
	temp = *head;
	while (ptr != NULL && ptr->next != NULL)
		ptr = ptr->next;
	while (temp != NULL && temp->next != ptr)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(head, ptr);
	if (boo)
		printf("rra\n");
}

void	ft_rrb(t_list **head, int boo)
{
	t_list *ptr;
	t_list *temp;

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
		printf("rrb\n");
}

void	ft_rrr(t_list **head_a, t_list **head_b)
{
	ft_rra(head_a, 0);
	ft_rrb(head_b, 0);
	printf("rrr\n");
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

int	ft_a_shorted(t_list *head)
{
	int		*nums;
	int		len;
	t_list	*temp;
	int		boo;

	len = 0;
	boo = 1;
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	temp = head;
	nums = (int *)malloc(sizeof(int) * (len + 1));
	nums[len] = '\0';
	len = 0;
	while (temp != NULL)
	{
		nums[len] = (int)temp->content;
		temp = temp->next;
		len++;
	}
	len = 0;
	while (nums[len] && nums[len + 1])
	{
		if (nums[len] > nums[len + 1])
			boo = 0;
		len++;
	}
	//free(nums);
	return (boo);
}

int	ft_check_pivot(t_list *head, int pivot)
{
	t_list *temp;

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
	t_list *temp;

	temp = head;
	while (temp != NULL)
	{
		if (temp->chunck == chunck)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_pass_a(t_list **head_a, t_list **head_b, int pivot, int chunck)
{
	t_list	*temp;
	int		rra;

	rra = 0;
	while (!ft_check_pivot(*head_a, pivot))
	{
		temp = *head_a;
		if ((int)temp->content < pivot)
		{
			temp->chunck = chunck;
			ft_pb(head_a, head_b);
		}
		else
		{
			ft_ra(head_a, 1);
			rra++;
		}
	}
	while (rra > 0)
	{
		temp = ft_lstlast(*head_a);
		if (temp->chunck == 0)
			return ;
		ft_rra(head_a, 1);
		rra--;
	}
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

void	ft_2_left_b(t_list **head_a, t_list **head_b)
{
	t_list	*temp_b;

	temp_b = *head_b;
	if (!temp_b || ft_chunck_size(head_b) == 1)
		return ;
	else
	{
		if (temp_b->content < temp_b->next->content)
			ft_sb(*head_b, 1);
		ft_pa(head_a, head_b);
		ft_pa(head_a, head_b);
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

void	ft_2_left_a(t_list **head_a)
{
	t_list *temp;

	temp = *head_a;
	if (ft_chunck_size(head_a) == 2)
	{
		if ((int)temp->content > (int)temp->next->content)
			ft_sa(*head_a, 1);
	}
}

void	ft_best_logic(t_list **head_a, t_list **head_b)
{
	int	pivot;
	int	chunck;

	chunck = 1;
	while (!ft_a_shorted(*head_a) || *head_b != NULL)
	{
		while (ft_chunck_size(head_a) > 2)
		{
			pivot = ft_index(*head_a);
			ft_pass_a(head_a, head_b, pivot, chunck);
			chunck++;
		}
		ft_2_left_a(head_a);
		pivot = ft_index(*head_b);
		ft_push_chunck_b(head_a, head_b, pivot);
	}
	//ft_print(*head_a, *head_b);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc == 1)
		exit(0);
	if (argc != 1 && argc != 2)
		ft_create_list(&head_a, argv + 1);
	else
		ft_create_list(&head_a, ft_split(argv[1], ' '));
	ft_best_logic(&head_a, &head_b);
	ft_print(head_a, head_b);
	return (0);
}
