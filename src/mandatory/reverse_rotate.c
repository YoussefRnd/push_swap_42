/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:44:52 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 22:56:56 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_stack **stack, char stack_name)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second_last;

	if (!stack)
		return ;
	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = ft_stack_last(*stack);
		second_last = last->prev;
		second_last->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
		if (stack_name == 'a')
			ft_putstr_fd("rra\n", 1);
		else if (stack_name == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_stack **x, t_stack **y)
{
	rotate(x, 'x');
	rotate(y, 'x');
	ft_putstr_fd("rrr\n", 1);
}
