/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:06:30 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/05 18:25:04 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_input_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;

	a = NULL;
	tmp = ft_split(argv[1], ' ');
	i = 0;
	while (tmp[i])
	{
		ft_add_back(&a, ft_stack_new(ft_atoi(tmp[i])));
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (a);
}

t_stack	*ft_input_process(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	if (argc > 2)
	{
		i = 1;
		while (i < argc)
		{
			ft_add_back(&a, ft_stack_new(ft_atoi(argv[i])));
			i++;
		}
	}
	else if (argc == 2)
		a = ft_input_sub_process(argv);
	return (a);
}
