/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:36:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/05 18:56:13 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*current;

	if (argc < 2)
		return (0);
	if (!ft_parser(argc, argv))
		return (1);
	a = ft_input_process(argc, argv);
	current = a;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	ft_stack_free(a);
	return (0);
}
