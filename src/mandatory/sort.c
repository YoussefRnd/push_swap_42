/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:19:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:22 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	adjust_ranges(int *first_range, int *end_range, int size)
{
	if (*end_range < size)
	{
		(*first_range)++;
		(*end_range)++;
	}
}

void	move_to_b(t_stack **a, t_stack **b)
{
	int	first_range;
	int	end_range;
	int	size;

	size = ft_stack_size(*a);
	first_range = 0;
	end_range = 0.0375 * size + 11.25;
	while (*a)
	{
		if ((*a)->index > first_range && (*a)->index < end_range)
		{
			push(a, b, 'b');
			adjust_ranges(&first_range, &end_range, size);
		}
		else if ((*a)->index <= first_range)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			adjust_ranges(&first_range, &end_range, size);
		}
		else if ((*a)->index >= end_range)
			rotate(a, 'a');
	}
}

void	move_back_to_a(t_stack **a, t_stack **b)
{
	int		i;
	int		max_index;
	t_stack	*temp;

	while (*b)
	{
		max_index = find_max_index(*b);
		i = 0;
		temp = *b;
		while (temp && temp->index != max_index)
		{
			temp = temp->next;
			i++;
		}
		while ((*b)->index != max_index)
		{
			if (i < max_index / 2)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
}
