/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_rvs_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:32 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 12:36:22 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_rvs_rotate(t_stack *stack)
{
	t_stk_item	*first;
	t_stk_item	*last;

	first = stack->items;
	if (!first)
		return ;
	last = ft_stk_last(stack);
	stack->items = first->next;
	first->next->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
	ft_printf("rr%c\n", stack->name);
}
