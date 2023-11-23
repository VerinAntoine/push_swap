/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:32:02 by averin            #+#    #+#             */
/*   Updated: 2023/11/22 11:14:16 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void		ft_stk_rotate(t_stack *stack)
{
	t_stk_item	*a;
	t_stk_item	*b;

	a = stack->items;
	if (!a)
		return ;
	b = ft_stk_last(stack);
	stack->items = b;
	b->previous->next = NULL;
	b->next = a;
	a->previous = b;
	b->previous = NULL;
}
