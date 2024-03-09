/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:21:48 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/07 18:33:23 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_add_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*last;

	if (!stack || !new_stack)
		return ;
	if (!*stack)
		*stack = new_stack;
	else
	{
		last = ft_stack_last(*stack);
		last->next = new_stack;
		new_stack->prev = last;
	}
}

t_stack	*ft_stack_new(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->next = NULL;
	new_stack->prev = NULL;
	return (new_stack);
}

void	ft_stack_free(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	ft_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*current;

	if (!stack)
		return (0);
	i = 0;
	current = stack;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
