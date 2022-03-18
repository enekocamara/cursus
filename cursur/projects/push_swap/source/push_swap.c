/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecamara <ecamara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:37:58 by ecamara           #+#    #+#             */
/*   Updated: 2022/03/11 13:39:44 by ecamara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		exit(0);
	if (argc != 1 && argc != 2)
		ft_create_list(&head_a, argv + 1, 0);
	else
		ft_create_list(&head_a, ft_split(argv[1], ' '), 1);
	if (ft_check_repeat(head_a))
	{
		ft_freelist(head_a);
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_chunck_size(&head_a) == 3)
		ft_case3(&head_a);
	ft_best_logic(&head_a, &head_b);
	ft_freelist(head_a);
	return (0);
}
