/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:42:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:42 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_max_index(t_stack *s)
{
	int	max_index;

	max_index = -1;
	while (s)
	{
		if (s->index > max_index)
			max_index = s->index;
		s = s->next;
	}
	return (max_index);
}

int	find_max_value(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (stack->value > i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	find_min_value(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (stack->value < i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}
