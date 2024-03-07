/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:51:28 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/07 16:27:09 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elements(t_stack **stack)
{
	int	max;

	max = find_max(*stack);
	if ((max == (*stack)->value))
	{
		rotate(stack, 'a');
		if ((*stack)->value > (*stack)->next->value)
			swap(stack, 'a');
	}
	else if (max == (*stack)->next->next->value)
	{
		if ((*stack)->value > (*stack)->next->value)
			swap(stack, 'a');
	}
	else
	{
		if ((*stack)->value > (*stack)->next->next->value)
			reverse_rotate(stack, 'a');
		else
		{
			swap(stack, 'a');
			rotate(stack, 'a');
		}
	}
}
