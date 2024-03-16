/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboumlak <yboumlak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:15:16 by yboumlak          #+#    #+#             */
/*   Updated: 2024/03/16 20:40:57 by yboumlak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

bool				is_valid_integer(char *input);
bool				check_duplicate(t_stack *stack, int num);
void				stack_init(t_stack **stack, char **argv, int argc);

t_stack				*ft_stack_new(int value);
t_stack				*ft_stack_last(t_stack *stack);
void				ft_add_back(t_stack **stack, t_stack *new_stack);
void				ft_stack_free(t_stack **stack);
int					ft_stack_size(t_stack *stack);

void				free_errors(t_stack **stack, char *msg);
void				ft_free(char **arr);
int					ft_arrlen(char **arr);

long				ft_atol(const char *str);

void				push(t_stack **x, t_stack **y, char stack_name);

void				swap(t_stack **stack, char stack_name);
void				ss(t_stack **a, t_stack **b);

void				rotate(t_stack **stack, char stack_name);
void				rr(t_stack **x, t_stack **y);

void				reverse_rotate(t_stack **stack, char stack_name);
void				rrr(t_stack **x, t_stack **y);

int					find_max(t_stack *stack);

void				sort_three(t_stack **stack);
void				sort(t_stack **a, t_stack **b);

#endif