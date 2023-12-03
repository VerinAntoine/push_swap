/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:27:41 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:02 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stack_swap(t_stack *stack)
{
	t_stack_item	*first;
	t_stack_item	*second;

	first = stack->items;
	if (!first)
		return ;
	second = first->next;
	if (!second)
		return ;
	if (second->next)
		second->next->previous = first;
	stack->items = second;
	first->next = second->next;
	second->next = first;
	first->previous = second;
	second->previous = NULL;
}
