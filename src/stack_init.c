/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:30 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/10 16:27:38 by yboumlak         ###   ########.fr       */
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
	int	i;
	int	num;

	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
	}
	else
		i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (!is_valid_integer(argv[i]))
			free_errors(stack, "Error: Invalid number!!");
		if (num > INT_MAX || num < INT_MIN)
			free_errors(stack, "Error: Number out of range!!");
		if (check_duplicate(*stack, num))
			free_errors(stack, "Error: Duplicate found!!");
		push_stack(stack, num);
		i++;
	}
	if (argc == 2)
		ft_free(argv);
}
