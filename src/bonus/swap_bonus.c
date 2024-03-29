/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:18:42 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/23 00:58:30 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack **stack, char stack_name)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		if (first->next)
			first->next->prev = first;
		second->next = first;
		second->prev = NULL;
		first->prev = second;
		*stack = second;
		if (stack_name == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (stack_name == 'b')
			ft_putstr_fd("sb\n", 1);
		update_indices(stack);
	}
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a, 0);
	swap(b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}
