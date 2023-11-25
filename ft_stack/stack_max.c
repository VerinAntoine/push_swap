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

int	stack_max(t_stack *s)
{
	t_stack_item	*item;
	int				max;

	item = s->items;
	if (!item)
		return (0);
	max = item->value;
	while (item)
	{
		if (max < item->value)
			max = item->value;
		item = item->next;
	}
	return (max);
}
