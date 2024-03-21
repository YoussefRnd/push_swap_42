/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:27:04 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/21 03:22:09 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	operations(t_stack **a, t_stack **b, char *command)
{
	if (ft_strncmp(command, "sa\n", 3))
		swap(a, 'a');
	else if (ft_strncmp(command, "sb\n", 3))
		swap(b, 'b');
	else if (ft_strncmp(command, "ss\n", 3))
		ss(a, b);
	else if (ft_strncmp(command, "pa\n", 3))
		push(b, a, 'a');
	else if (ft_strncmp(command, "pb\n", 3))
		push(a, b, 'b');
	else if (ft_strncmp(command, "ra\n", 3))
		rotate(a, 'a');
	else if (ft_strncmp(command, "rb\n", 3))
		rotate(b, 'b');
	else if (ft_strncmp(command, "rr\n", 3))
		rr(a, b);
	else if (ft_strncmp(command, "rra\n", 4))
		reverse_rotate(a, 'a');
	else if (ft_strncmp(command, "rrb\n", 4))
		reverse_rotate(b, 'b');
	else if (ft_strncmp(command, "rrr\n", 4))
		rrr(a, b);
	else
	{
		ft_putstr_fd("KO\n", 2);
		exit(1);
	}
}
// int get_next_line(int fd);

void read_commands(t_stack **a, t_stack **b)
{
	char *line;
	int ret;

	line = NULL;
	while ((ret = get_next_line(0)) > 0)
	{
		operations(a, b, line);
		free(line);
	}
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}


int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_init(&a, argv, argc);
	read_commands(&a, &b);
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	return (0);
}