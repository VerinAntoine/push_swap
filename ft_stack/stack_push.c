/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:18:22 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 12:35:23 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	stack_push(t_stack *from, t_stack *to)
{
	t_stack_item	*item;

	item = from->items;
	item->next->previous = NULL;
	from->items = item->next;
	item->next = to->items;
	to->items = item;
}
