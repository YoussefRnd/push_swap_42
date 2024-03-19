/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/18 22:49:08 by yboumlak         ###   ########.fr       */
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

int	is_sorted(t_stack *x)
{
	if (x == NULL)
		return (false);
	while (x->next != NULL)
	{
		if (x->value > x->next->value)
			return (false);
		x = x->next;
	}
	return (true);
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
	// print_stacks(a, b);
	set_sorted_index(a);
	move_to_b(&a, &b);
	move_back_to_a(&a, &b);
	// print_stacks(a, b);
	// if (is_sorted(a))
	// 	printf("you got it!!!!!!!");
	// else
	// 	printf("ghi katkhwer");
	ft_stack_free(&a);
	return (0);
}
