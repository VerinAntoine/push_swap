/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:19:53 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 14:37:51 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ps_cost_r(t_stack *a, int value, size_t index)
{
	size_t	size_a;
	size_t	dest;
	size_t	cost;
	int		op;

	op = direction(a, value);
	dest = stack_index(a, value);
	cost = 0;
	size_a = stack_size(a);
	while (index || dest)
	{
		if (dest && cost++)
		{
			if (op == OP_R)
				dest--;
			else
				dest++;
			if (dest == size_a)
				dest = 0;
		}
		if (index)
			index--;
		cost++;
	}
	return (cost);
}

static size_t	ps_cost_rr(t_stack *a, int value, size_t index, size_t sizes[2])
{
	size_t	dest;
	size_t	cost;
	int		op;

	op = direction(a, value);
	dest = stack_index(a, value);
	cost = 0;
	while (index || dest)
	{
		if (dest && cost++)
		{
			if (op == OP_R)
				dest--;
			else
				dest++;
			if (dest == sizes[0])
				dest = 0;
		}
		if (index)
			index++;
		if (index == sizes[1])
			index = 0;
		cost++;
	}
	return (cost);
}

void	ps_cost(t_stack	*a, t_stack *b)
{
	t_stack_item	*item;
	size_t			i;
	size_t			cost_r;
	size_t			cost_rr;
	size_t			sizes[2];

	sizes[0] = stack_size(a);
	sizes[1] = stack_size(b);
	i = 0;
	item = b->items;
	while (item)
	{
		cost_r = ps_cost_r(a, item->value, i);
		cost_rr = ps_cost_rr(a, item->value, i, sizes);
		if (cost_r <= cost_rr)
			item->operator = OP_R;
		else
			item->operator = OP_RR;
		item->cost = ft_min(cost_r, cost_rr);
		item = item->next;
		i++;
	}
}
