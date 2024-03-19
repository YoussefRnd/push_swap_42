/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:19:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/19 01:33:59 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_to_b(t_stack **a, t_stack **b)
{
	int	first_range;
	int	end_range;
	int	size;

	size = ft_stack_size(*a);
	first_range = 0;
	end_range = 8.5 + (size * 0.055);
	while (*a)
	{
		if ((*a)->index >= first_range && (*a)->index < end_range)
		{
			push(a, b, 'b');
			if (end_range < size)
			{
				first_range++;
				end_range++;
			}
		}
		else if ((*a)->index < first_range)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			if (end_range < size)
			{
				first_range++;
				end_range++;
			}
		}
		else if ((*a)->index >= end_range)
			rotate(a, 'a');
	}
}

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
			if (i < max_index / 2)
			{
				while ((*b)->index != max_index)
					rotate(b, 'b');
			}
			else
			{
				while ((*b)->index != max_index)
					reverse_rotate(b, 'b');
			}
		}
		push(b, a, 'a');
	}
}
