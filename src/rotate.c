/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:35:47 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 14:12:37 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack, char stack_name)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = ft_stack_last(*stack);
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
		if (stack_name == 'a')
			ft_putstr_fd("ra\n", 1);
		else if (stack_name == 'b')
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack **x, t_stack **y)
{
	rotate(x, 'x');
	rotate(y, 'y');
	ft_putstr_fd("rr\n", 1);
}
