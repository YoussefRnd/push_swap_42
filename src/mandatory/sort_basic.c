/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:51:28 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:16 by yboumlak         ###   ########.fr       */
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

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min = find_min_value(*a);
		while ((*a)->value != min)
			rotate(a, 'a');
		push(a, b, 'b');
		i++;
	}
	sort_three(a);
	while (i > 0)
	{
		push(b, a, 'a');
		i--;
	}
}
