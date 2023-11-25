/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:32:02 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:24 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stack_rotate(t_stack *stack)
{
	t_stack_item	*first;
	t_stack_item	*last;

	first = stack->items;
	if (!first)
		return ;
	last = stack_last(stack);
	if (first == last)
		return ;
	stack->items = last;
	if (last->previous)
		last->previous->next = NULL;
	first->next = last->next;
	last->next = first;
	first->previous = last;
	last->previous = NULL;
}
