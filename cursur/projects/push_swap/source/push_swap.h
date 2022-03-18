/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:07:38 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/11 13:23:12 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/*------------INPUT-------------*/

t_list	*ft_lstnew_ps(size_t content);
int		ft_check(char *str);
void	ft_create_list(t_list **head_a, char **str, int boo);
int		ft_check_repeat(t_list *head);

/*------------LOGIC-------------*/

void	ft_best_logic(t_list **head_a, t_list **head_b);
void	ft_push_chunck_b(t_list **head_a, t_list **head_b, int pivot);
void	ft_pass_a(t_list **head_a, t_list **head_b, int pivot, int chunck);

void	ft_2_left_b(t_list **head_a, t_list **head_b);
void	ft_2_left_a(t_list **head_a);
int		ft_a_shorted(t_list *head);
void	ft_case3(t_list **head);

/*------------COMMANDS-----------*/

void	ft_sa(t_list *head, int boo);
void	ft_sb(t_list *head, int boo);
void	ft_ss(t_list *head_a, t_list *head_b);
void	ft_pa(t_list **head_a, t_list **head_b);
void	ft_pb(t_list **head_a, t_list **head_b);

void	ft_ra(t_list **head, int boo);
void	ft_rb(t_list **head, int boo);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_rra(t_list **head, int boo);
void	ft_rrb(t_list **head, int boo);

void	ft_rrr(t_list **head_a, t_list **head_b);

/*----------------AUX---------------*/

int		ft_check_pivot(t_list *head, int pivot);
int		ft_chunck_b_pushed(t_list *head, int chunck);
int		ft_index(t_list *head);
int		ft_quick_short(int **nums, int len);
int		ft_chunck_size(t_list **head);

/*-------------ERROR_FREE------------*/

void	ft_error2(char **str, int boo, t_list **head_a);
void	ft_free2str(char **str, int boo);
void	ft_freelist(t_list *head);
void	ft_error(void);
void	ft_check_before(char **str, int boo);

#endif