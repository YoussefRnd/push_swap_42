/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/07 16:24:47 by yboumlak         ###   ########.fr       */
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
			printf("%d <- %d -> %d\t\t\t\t\t", (a->prev ? a->prev->value :
					-256), a->value, (a->next ? a->next->value : -256));
			a = a->next;
		}
		else
			printf("\t\t\t\t\t\t");
		if (b)
		{
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
	if (argc < 2)
		return (0);
	if (!ft_parser(argc, argv))
		return (1);
	a = ft_input_process(argc, argv);
	print_stacks(a, b);
	bubble_sort_stack(&a);
	print_stacks(a, b);
	ft_stack_free(a);
	return (0);
}
