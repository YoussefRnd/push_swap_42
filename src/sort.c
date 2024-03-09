/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:19:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 09:55:19 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) > 3)
	{
		push(a, b, 'a');
		push(a, b, 'a');
	}
}

int	calculate_cost(t_stack *node, t_stack *b)
{
	int		cost;
	t_stack	*temp;

	cost = 0;
	temp = b;
	// Calculate the number of push operations required
	while (temp && node->value > temp->value)
	{
		cost++;
		temp = temp->next;
	}
	// Calculate the number of rotate operations required
	temp = node;
	while (temp)
	{
		cost++;
		temp = temp->next;
	}
	return (cost);
}

void	move_to_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	// Rotate STACK_A until the cheapest number is at the top
	while (*a != cheapest)
	{
		rotate(a, 'a');
	}
	// Push the cheapest number to STACK_B
	push(a, b, 'a');
}

void	find_and_push_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		cost;

	current = *a;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		cost = calculate_cost(current, *b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	// Now cheapest is the number that requires the fewest operations
	// to move to its correct position in STACK_B.
	// You can now perform the operations to move cheapest to STACK_B.
	// Note: You'll need to implement the move_to_b function.
	if (cheapest)
	{
		move_to_b(a, b, cheapest);
	}
}
