/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:10:19 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 13:35:38 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include "libft.h"

typedef struct s_stack_item {
	int					value;
	struct s_stack_item	*next;
	struct s_stack_item	*previous;
}	t_stack_item;

typedef struct s_stack {
	t_stack_item	*items;
	char		name;
}	t_stack;

void		ft_stk_swap(t_stack *stack);
void		ft_stk_push(t_stack *from, t_stack *to);
void		ft_stk_rotate(t_stack *stack);
void		ft_stk_rvs_rotate(t_stack *stack);

int			ft_stk_is_ordered(t_stack *stack);
int			ft_stk_add(t_stack *stack, int value);
void		ft_stk_remove(t_stack *stack, t_stack_item *item);
void		ft_stk_free(t_stack *stack);
void		ft_stk_print(t_stack *stack);
t_stack_item	*ft_stk_last(t_stack *stack);

#endif
