/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:19:13 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 15:22:23 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(char *arr)
{
	if ((*arr == '+' || *arr == '-') && *(arr + 1) != '\0')
		arr++;
	while (*arr)
	{
		if (!ft_isdigit(*arr))
		{
			return (false);
		}
		arr++;
	}
	return (true);
}

int	check_duplicate(t_stack *stack, int num)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

bool	check_syntax(char *input)
{
	if (is_number(input))
		return (true);
	return (false);
}

void	free_errors(t_stack **stack)
{
	ft_stack_free(stack);
	ft_putstr_fd("Error!\n", 2);
}
