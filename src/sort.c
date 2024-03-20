/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:19:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/20 02:17:02 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	process_index(t_stack **a, t_stack **b, int *first_range,
		int *end_range, int size)
{
	if ((*a)->index >= *first_range && (*a)->index < *end_range)
	{
		push(a, b, 'b');
		if (*end_range < size)
		{
			(*first_range)++;
			(*end_range)++;
		}
	}
	else if ((*a)->index < *first_range)
	{
		push(a, b, 'b');
		rotate(b, 'b');
		if (*end_range < size)
		{
			(*first_range)++;
			(*end_range)++;
		}
	}
	else if ((*a)->index >= *end_range)
		rotate(a, 'a');
}

void	move_to_b(t_stack **a, t_stack **b)
{
	int	first_range;
	int	size;
	int	end_range;

	first_range = 0;
	size = ft_stack_size(*a);
	end_range = 8.5 + (size * 0.055);
	while (*a)
		process_index(a, b, &first_range, &end_range, size);
}

void	move_back_to_a(t_stack **a, t_stack **b)
{
	int		i;
	int		max_index;
	t_stack	*temp;

	while (*b)
	{
		max_index = find_max_index(*b);
		while ((*b)->index != max_index)
		{
			i = 0;
			temp = *b;
			while (temp && temp->index != max_index)
			{
				temp = temp->next;
				i++;
			}
			while ((*b)->index != max_index)
				if (i < max_index / 2)
					rotate(b, 'b');
				else
					reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
}
