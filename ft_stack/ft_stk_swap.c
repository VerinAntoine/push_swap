/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:27:41 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 12:34:36 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_swap(t_stack *stack)
{
	t_stk_item	*second;
	t_stk_item	*first;
	
	second = stack->items;
	first = second->next;
	stack->items = first;
	second->next = first->next;
	first->next = second;
	second->previous = first;
	first->previous = NULL;
	ft_printf("s%c\n", stack->name);
}
