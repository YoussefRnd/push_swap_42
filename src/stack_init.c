/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:30 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/16 20:41:16 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_stack(t_stack **stack, int num)
{
	t_stack	*new_node;

	new_node = ft_stack_new(num);
	if (!new_node)
	{
		ft_stack_free(stack);
		return ;
	}
	ft_add_back(stack, new_node);
}

void	stack_init(t_stack **stack, char **argv, int argc)
{
	int		i;
	int		j;
	char	**split_args;
	long	num;

	i = 1;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		j = 0;
		while (split_args[j])
		{
			num = ft_atol(split_args[j]);
			if (!is_valid_integer(split_args[j]))
				free_errors(stack, "Error: Invalid number!!");
			if (num > INT_MAX || num < INT_MIN)
				free_errors(stack, "Error: Number out of range!!");
			if (check_duplicate(*stack, num))
				free_errors(stack, "Error: Duplicate found!!");
			push_stack(stack, num);
			j++;
		}
		ft_free(split_args);
		i++;
	}
}
