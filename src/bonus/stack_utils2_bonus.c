/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 03:42:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/22 22:28:33 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_max_index(t_stack *s)
{
	int		max_index;
	t_stack	*max_node;

	max_index = INT_MIN;
	max_node = NULL;
	while (s)
	{
		if (s->sorted_index > max_index)
		{
			max_index = s->sorted_index;
			max_node = s;
		}
		s = s->next;
	}
	return (max_node);
}

t_stack	*find_min_index(t_stack *s)
{
	int		min_index;
	t_stack	*min_node;

	min_index = INT_MAX;
	min_node = NULL;
	while (s)
	{
		if (s->sorted_index < min_index)
		{
			min_index = s->sorted_index;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
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

void	update_indices(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}
