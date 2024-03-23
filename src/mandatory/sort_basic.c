/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:51:28 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/23 00:10:41 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_max_value(*stack);
	if (max == (*stack)->value)
		rotate(stack, 'a');
	else if (max == (*stack)->next->value)
		reverse_rotate(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min_index(*a);
	while ((*a)->value != min->value)
	{
		if (min->index <= ft_stack_size(*a) / 2)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min_index(*a);
	while ((*a)->value != min->value)
	{
		if (min->index <= ft_stack_size(*a) / 2)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
	sort_four(a, b);
	push(b, a, 'a');
}

void	reverse_stack(t_stack **a, t_stack **b)
{
	while (*a)
	{
		reverse_rotate(a, 'a');
		push(a, b, 'b');
	}
	while (*b)
		push(b, a, 'a');
}
