/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:19:13 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/03 12:44:00 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(char *arr)
{
	int	len;

	if ((*arr == '+' || *arr == '-') && *(arr + 1) != '\0')
		arr++;
	while (*arr)
	{
		len = ft_strlen(arr);
		if (!ft_isdigit(*arr))
		{
			return (-1);
		}
		if (len > 10 || (len == 10 && ft_strncmp(arr, "2147483647", 10) > 0))
		{
			return (-2);
		}
		arr++;
	}
	return (1);
}

int	is_there_duplicate(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if ((ft_strncmp(arr[i], arr[j], INT_MAX) == 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_parser(char **arr)
{
	int	i;
	int	is_num;

	i = 1;
	while (arr[i])
	{
		is_num = is_number(arr[i]);
		if (is_num == -1)
		{
			ft_putstr_fd("Error: NOT A NUMBER!!", 2);
			return (NULL);
		}
		else if (is_num == -2)
		{
			ft_putstr_fd("Error: NUMBER IS LARGER THAN INT_MAX!!", 2);
			return (NULL);
		}
		i++;
	}
	if (is_there_duplicate(arr))
	{
		ft_putstr_fd("Error: THERE IS A DUPLICATE!!", 2);
		return (NULL);
	}
	return (arr);
}
