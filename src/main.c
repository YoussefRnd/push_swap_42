/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/20 22:00:09 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("Stack A\t\t\t\t\t\tStack B\n");
	printf("------\t\t\t\t\t\t------\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d) ", a->index);
			printf("%d <- %d -> %d\t\t\t\t\t", (a->prev ? a->prev->value :
					-256), a->value, (a->next ? a->next->value : -256));
			a = a->next;
		}
		else
			printf("\t\t\t\t\t\t");
		if (b)
		{
			printf("%d) ", b->index);
			printf("%d <- %d -> %d\n", b->prev ? b->prev->value : -256,
				b->value, b->next ? b->next->value : -256);
			b = b->next;
		}
		else
			printf("\n");
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
	if (is_sorted(a) == false)
	{
		if (ft_stack_size(a) == 2)
			swap(&a, 'a');
		else if (ft_stack_size(a) == 3)
			sort_three(&a);
		else if (ft_stack_size(a) == 5)
			sort_five(&a, &b);
		else
		{
			move_to_b(&a, &b);
			move_back_to_a(&a, &b);
		}
	}
	// print_stacks(a, b);
	ft_free_stack(&a);
	return (0);
}
