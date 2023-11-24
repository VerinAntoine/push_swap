/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:50:50 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 12:53:37 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stack_item	*stack_last(t_stack *stack)
{
	t_stack_item	*item;

	item = stack->items;
	if (item == NULL)
		return (NULL);
	while (item->next)
		item = item->next;
	return (item);
}
