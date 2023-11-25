/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:14:29 by antoine           #+#    #+#             */
/*   Updated: 2023/11/25 12:16:43 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_max(t_stack *s, int *min, int *max)
{
	t_stack_item	*item;

	item = s->items;
	if (!item)
		return ;
	*max = item->value;
	*min = item->value;
	while (item)
	{
		if (*max < item->value)
			*max = item->value;
		if (*min > item->value)
			*min = item->value;
		item = item->next;
	}
	return ;
}
