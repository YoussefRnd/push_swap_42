/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:48:18 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:11 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	fill_array(int *arr, t_stack *stack, int size)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stack;
	while (i < size)
	{
		arr[i] = temp->value;
		temp = temp->next;
		i++;
	}
}

static void	set_index(t_stack *stack, int *arr, int size)
{
	int		i;
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->value == arr[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	set_sorted_indeces(t_stack *stack)
{
	int	*arr;
	int	size;

	size = ft_stack_size(stack);
	arr = (int *)malloc(sizeof(int) * size);
	fill_array(arr, stack, size);
	quick_sort(arr, 0, size - 1);
	set_index(stack, arr, size);
	free(arr);
}
