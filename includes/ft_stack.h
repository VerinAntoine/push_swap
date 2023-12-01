/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:10:19 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 09:32:12 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include "libft.h"
# define OP_R 1
# define OP_RR 2

typedef struct s_stack_item {
	int					value;
	struct s_stack_item	*next;
	struct s_stack_item	*previous;
	size_t				index;
	size_t				cost;
	int					operator;
}	t_stack_item;

typedef struct s_stack {
	t_stack_item	*items;
	char			name;
}	t_stack;

void			stack_swap(t_stack *stack);
void			stack_push(t_stack *from, t_stack *to);
void			stack_rotate(t_stack *stack);
void			stack_rvs_rotate(t_stack *stack);

int				stack_is_ordered(t_stack *stack);
int				stack_add(t_stack *stack, int value);
void			stack_max(t_stack *s, int *min, int *max);
void			stack_free(t_stack *stack);
void			stack_print(t_stack *stack);
t_stack_item	*stack_last(t_stack *stack);
size_t			stack_index(t_stack *s, int n);
size_t			stack_size(t_stack *s);

#endif
