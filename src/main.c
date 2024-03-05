/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/05 21:52:08 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("Stack A\tStack B\n");
	printf("------\t------\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d\t", a->value);
			a = a->next;
		}
		else
			printf(" \t");
		if (b)
		{
			printf("%d\n", b->value);
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
	swap(&a, 'a');
	print_stacks(a, b);
	ft_stack_free(a);
	return (0);
}
