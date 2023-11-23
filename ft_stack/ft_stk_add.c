/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:46:14 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:06 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

//TODO: Escalade error
void	ft_stk_add(t_stack *stack, int value)
{
	t_stk_item	*item;

	item = ft_calloc(1, sizeof(t_stk_item));
	if (!item)
		return ;
	item->value = value;
	if (!stack->items)
		stack->items = item;
	else
	{
		item->previous = ft_stk_last(stack);
		ft_stk_last(stack)->next = item;
	}
}
