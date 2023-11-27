/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:30:43 by averin            #+#    #+#             */
/*   Updated: 2023/11/27 15:42:51 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_stack_item	*item;
	size_t			size;
	int				min;
	t_stack_item	*highest;

	size = stack_size(a);
	while (--size)
	{
		min = INT_MIN;
		highest = NULL;
		item = a->items;
		while (item)
		{
			if (min < item->value && !item->index)
			{
				min = item->value;
				highest = item;
			}
			item = item->next;
		}
		highest->index = size;
	}
}

void	ps_presort(t_stack *a, t_stack *b)
{
	assign_index(a);
	while ()
}
