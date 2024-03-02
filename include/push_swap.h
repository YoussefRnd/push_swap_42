/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:15:16 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/02 22:53:06 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft/libft.h"
# include <limits.h>
// typedef struct s_stack
// {
// 	int				nbr;
// 	int				index;
// 	struct s_stack	*next;
// }					t_stack;

char	**ft_parser(char **inputs);
void	bubble_sort(char **arr, int n);

#endif