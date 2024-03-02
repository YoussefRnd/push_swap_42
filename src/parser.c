/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 22:19:13 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/02 23:50:39 by yboumlak         ###   ########.fr       */
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
	if (is_there_duplicate(arr))
	{
		printf("There is a duplicate!\n");
	}
	return (arr);
}
