/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:37 by antoine           #+#    #+#             */
/*   Updated: 2023/11/25 14:17:25 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	direction(t_stack *s, int n)
{
	t_stack_item	*item;
	int				max;
	int				min;
	int				last;
	size_t			i;

	// stack_index?
	if (!s->items)
		return (-1);
	item = s->items;
	last = item->value;
	stack_max(s, &min, &max);
	i = 0;
	while (item)
	{

		item = item->next;
		i++;
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
	push_all(a, b);
	while (b->items)
	{
		align(a, b->items->value);
		ps_px(b, a);
	}
	while (!stack_is_ordered(a))
		ps_rx(a);
}
