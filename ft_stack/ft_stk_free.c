/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:18:03 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:55:20 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_free(t_stack *stack)
{
	t_stk_item	*item;
	t_stk_item	*next;

	item = stack->items;
	while (item)
	{
		next = item->next;
		free(item);
		item = next;
	}
	free(stack);
}
