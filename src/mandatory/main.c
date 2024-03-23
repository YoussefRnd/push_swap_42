/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/23 01:27:05 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	printf("Stack A:\n");
	while (current != NULL)
	{
		printf("%d <- %d -> %d, Index: %d, Sorted Index: %d\n",
			(current->prev != NULL) ? current->prev->value : -0, current->value,
			(current->next != NULL) ? current->next->value : -0, current->index,
			current->sorted_index);
		current = current->next;
	}
	printf("\n");
}

void	sorting(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) == 2)
		swap(a, 'a');
	else if (ft_stack_size(*a) == 3)
		sort_three(a);
	else if (ft_stack_size(*a) == 4)
		sort_four(a, b);
	else if (ft_stack_size(*a) == 5)
		sort_five(a, b);
	else
	{
		move_to_b(a, b);
		move_back_to_a(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_init(&a, argv, argc);
	set_sorted_indeces(a);
	if (is_rsorted(a) == true && ft_stack_size(a) > 5)
		reverse_stack(&a, &b);
	else if (is_sorted(a) == false)
		sorting(&a, &b);
	// print_stack(a);
	ft_free_stack(&a);
	return (0);
}
