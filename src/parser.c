/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:19:13 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/02 19:37:12 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(char *arr)
{
	if ((*arr == '+' || *arr == '-') && *(arr + 1) != '\0')
		arr++;
	while (*arr)
	{
		if (!ft_isdigit(*arr))
		{
			return (0);
		}
		arr++;
	}
	return (1);
}

void	is_there_duplicate(char **arr)
{
	while (*arr)
	{
		
	}
}

char	**ft_parser(char **arr)
{
	int	i;

	i = 1;
	while (arr[i])
	{
		if (!is_number(arr[i]))
		{
			printf("Error: %s is not a number\n", arr[i]);
			return (NULL);
		}
		i++;
	}
	return (arr);
}
