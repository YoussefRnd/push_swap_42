/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:23:35 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/22 20:52:19 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack **x, t_stack **y, char stack_name)
{
	t_stack	*temp;

	if (*x)
	{
		temp = *x;
		*x = (*x)->next;
		if (*x)
			(*x)->prev = NULL;
		temp->next = *y;
		if (*y)
			(*y)->prev = temp;
		*y = temp;
		if (stack_name == 'a')
			ft_putstr_fd("pa\n", 1);
		else if (stack_name == 'b')
			ft_putstr_fd("pb\n", 1);
		update_indices(x);
		update_indices(y);
	}
}
