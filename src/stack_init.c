/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:30 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 15:25:41 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_stack(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = ft_stack_new(num);
	if (!new_node)
	{
		ft_putstr_fd("Error: Failed to allocate memory for new node", 2);
		ft_stack_free(stack);
	}
	ft_add_back(stack, new_node);
}

void	stack_init(t_stack **stack, char **argv)
{
	int	i;
	int	num;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			free_errors(stack);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(stack);
		if (check_duplicate(*stack, num))
			free_errors(stack);
		push_stack(stack, num);
		i++;
	}
}
