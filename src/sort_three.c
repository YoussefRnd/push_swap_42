/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:51:28 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 11:06:01 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_max(*stack);
	if (max == (*stack)->value)
		rotate(stack, 'a');
	else if (max == (*stack)->next->value)
		reverse_rotate(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 'a');
}
