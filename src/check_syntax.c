/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:19:13 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/19 03:25:45 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_valid_integer(char *input)
{
	if ((*input == '+' || *input == '-') && *(input + 1) != '\0')
		input++;
	while (*input)
	{
		if (!ft_isdigit(*input))
			return (false);
		input++;
	}
	return (true);
}

bool	check_duplicate(t_stack *stack, int num)
{
	if (!stack)
		return (false);
	while (stack)
	{
		if (stack->value == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}
