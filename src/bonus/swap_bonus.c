/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:18:42 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/22 01:48:15 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

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
	}
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 'x');
	swap(b, 'x');
	ft_putstr_fd("ss\n", 1);
}
