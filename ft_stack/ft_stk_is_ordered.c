/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_is_ordered.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:43 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 12:54:31 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stk_is_ordered(t_stack *stack)
{
	t_stack_item	*item;

	item = stack->items;
	if (item == NULL)
		return (FALSE);
	while (item->next)
	{
		if (item->value > item->next->value)
			return (FALSE);
	}
	return (TRUE);
}
