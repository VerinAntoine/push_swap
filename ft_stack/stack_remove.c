/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:56:34 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 13:35:26 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stack_remove(t_stack *stack, t_stack_item *item)
{
	if (item->previous)
		item->previous->next = item->next;
	if (item->next)
		item->next->previous = item->previous;
	if (stack->items == item)
		stack->items = item->next;
	free(item);
}
