/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:18:03 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:20 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stack_free(t_stack *stack)
{
	t_stack_item	*item;
	t_stack_item	*next;

	item = stack->items;
	while (item)
	{
		next = item->next;
		free(item);
		item = next;
	}
	free(stack);
}
