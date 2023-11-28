/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:30:43 by averin            #+#    #+#             */
/*   Updated: 2023/11/28 15:29:47 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack	*s)
{
	int	one;
	int	two;
	int	three;

	one = s->items->value;
	two = s->items->next->value;
	three = s->items->next->next->value;
	if (one > two && one > three)
	{
		ps_rx(s);
		if (two > three)
			ps_sx(s);
	}
	else if (two > one && two > three)
	{
		ps_rrx(s);
		if (three > one)
			ps_sx(s);
	}
	else if (three > one && three > two)
	{
		if (one > two)
			ps_sx(s);
	}
}

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
	size_t	size;
	size_t	i;

	i = 0;
	size = stack_size(a);
	assign_index(a);
	while (i < size / 2)
	{
		if (a->items->index < size / 2)
		{
			i++;
			ps_px(a, b);
		}
		ps_rx(a);
	}
	while (++i <= size - 3)
		ps_px(a, b);
	sort_three(a);
}
