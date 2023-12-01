/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:37 by antoine           #+#    #+#             */
/*   Updated: 2023/12/01 09:04:58 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	direction(t_stack *s, int n)
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
	// ft_printf("%d should go at %d (size=%d)\n", n, index, size);
	if (index > size / 2)
		return (2);
	else
		return (1);
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
		ps_rx(s);
	}
}

void	ps_sort(t_stack *a, t_stack *b)
{
	size_t	op;

	ps_presort(a, b);
	while (b->items)
	{
		// read(0, &c, 1);
		op = direction(a, b->items->value);
		if (op == 1)
			align(a, b->items->value);
		else
			ralign(a, b->items->value);
		ps_px(b, a);
	}
	op = a->items->index / stack_size(a);
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
