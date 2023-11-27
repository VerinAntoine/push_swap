/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:37 by antoine           #+#    #+#             */
/*   Updated: 2023/11/27 13:57:19 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	direction(t_stack *s, int n)
{
	size_t	size;
	size_t	index;
	int		max;
	int		min;

	if (!s->items)
		return (-1);
	stack_max(s, &min, &max);
	size = stack_size(s);
	if (n < min)
		index = stack_index(s, min);
	else if (n > max)
		index = stack_index(s, max);
	else
		index = stack_index(s, n);
	if (index >= size / 2)
		return (1);
	else
		return (2);
}

static void	ralign(t_stack *s, int n)
{
	int	max;
	int	min;
	int	last;

	if (!s->items)
		return ;
	stack_max(s, &min, &max);
	while (s->items)
	{
		last = stack_last(s)->value;
		if (n < min && s->items->value == min)
			break ;
		if (n > max && s->items->value == max)
		{
			ps_rx(s);
			break ;
		}
		if (s->items->value > n && last < n)
			break ;
		ps_rrx(s);
	}
}

static void	align(t_stack *s, int n)
{
	int	max;
	int	min;
	int	last;

	if (!s->items)
		return ;
	last = s->items->value;
	stack_max(s, &min, &max);
	while (s->items)
	{
		if (n < min && s->items->value == min)
			break ;
		if (n > max && s->items->value == max)
		{
			ps_rx(s);
			break ;
		}
		if (s->items->value > n && last < n)
			break ;
		last = s->items->value;
		ps_rx(s);
	}
}

static void	push_all(t_stack *from, t_stack *to)
{
	t_stack_item	*item;

	item = from ->items;
	while (item)
	{
		ps_px(from, to);
		item = from ->items;
	}
}

void	ps_sort(t_stack *a, t_stack *b)
{
	int	op;

	push_all(a, b);
	while (b->items)
	{
		op = direction(a, b->items->value);
		if (op == 1)
			align(a, b->items->value);
		else
			ralign(a, b->items->value);
		ps_px(b, a);
		// stack_print(a);
	}
	while (!stack_is_ordered(a))
		ps_rx(a);
}
