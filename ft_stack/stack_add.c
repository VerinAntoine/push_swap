/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:46:14 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:06 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	stack_add(t_stack *stack, int value)
{
	t_stack_item	*item;
	t_stack_item	*last;

	item = ft_calloc(1, sizeof(t_stack_item));
	if (!item)
		return (FALSE);
	item->value = value;
	item->index = 0;
	if (!stack->items)
		stack->items = item;
	else
	{
		last = stack_last(stack);
		item->previous = last;
		last->next = item;
	}
	return (TRUE);
}
