/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:37 by antoine           #+#    #+#             */
/*   Updated: 2023/12/01 15:28:08 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	direction(t_stack *s, int n)
{
	size_t	size;
	size_t	index;

	if (!s->items)
		return (-1);
	size = stack_size(s);
	index = stack_index(s, n);
	if (index > size / 2)
		return (OP_RR);
	else
		return (OP_R);
}

static size_t	exact_index(t_stack *s, int value)
{
	t_stack_item	*item;
	size_t			index;

	index = 0;
	item = s->items;
	while (item)
	{
		if (item->value == value)
			return (index);
		item = item->next;
		index++;
	}
	return (0);
}

t_stack_item	*select_costless(t_stack *b)
{
	t_stack_item	*item;
	t_stack_item	*result;

	item = b->items;
	result = item;
	while (item)
	{
		if (result->cost > item->cost)
			result = item;
		item = item->next;
	}
	return (result);
}

void	ps_sort(t_stack *a, t_stack *b)
{
	size_t			op;
	t_stack_item	*item;
	int				min;
	int				max;

	ps_presort(a, b);
	while (b->items)
	{
		stack_max(a, &min, &max);
		ps_cost(a, b);
		item = select_costless(b);
		if (item->operator == OP_R)
			align(a, b, item->value, exact_index(b, item->value));
		else
			ralign(a, b, item->value, exact_index(b, item->value));
		if (item->value > max)
			ps_rx(a);
		ps_px(b, a);
	}
	stack_max(a, &min, &max);
	op = direction(a, min);
	while (!stack_is_ordered(a))
	{
		if (op == 1)
			ps_rx(a);
		else
			ps_rrx(a);
	}
}

void	dispatch_sort(t_stack *a, t_stack *b)
{
	size_t	size;

	size = stack_size(a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
		ps_sort(a, b);
}
