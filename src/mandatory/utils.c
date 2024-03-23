/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:55:33 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/23 00:10:35 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
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

int	is_rsorted(t_stack *x)
{
	if (x == NULL)
		return (false);
	while (x->next != NULL)
	{
		if (x->value < x->next->value)
			return (false);
		x = x->next;
	}
	return (true);
}

long	ft_atol(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}
