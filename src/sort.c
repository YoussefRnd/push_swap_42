/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:19:50 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/09 15:34:19 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (ft_stack_size(*a) > 3)
	{
		push(a, b, 'a');
		push(a, b, 'a');
	}
}
