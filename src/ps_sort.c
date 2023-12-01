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

// static void	ralign(t_stack *s, int n)
// {
// 	int	max;
// 	int	min;
// 	int	last;

// 	if (!s->items)
// 		return ;
// 	stack_max(s, &min, &max);
// 	while (s->items)
// 	{
// 		last = stack_last(s)->value;
// 		if (n < min && s->items->value == min)
// 			break ;
// 		if (n > max && s->items->value == max)
// 		{
// 			ps_rx(s);
// 			break ;
// 		}
// 		if (s->items->value > n && last < n)
// 			break ;
// 		ps_rrx(s);
// 	}
// }

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

static void	ralign(t_stack *a, t_stack *b, int value, size_t index)
{
	size_t	dest;
	int		dir;

	dest = stack_index(a, value);
	dir = direction(a, value);
	while (index || dest)
	{
		if (index && dest && dir == OP_RR && index++ && dest++)
			ps_rrr(a, b);
		else
		{
			if (index && index++)
				ps_rrx(b);
			if (dest)
			{
				if (dir == OP_R && dest--)
					ps_rx(a);
				else if (dir == OP_RR && dest++)
					ps_rrx(a);
				
			}
		}
		if (index == stack_size(b))
			index = 0;
		if (dest == stack_size(a))
			dest = 0;
		
	}
}

static void	align(t_stack *a, t_stack *b, int value, size_t index)
{
	size_t	dest;
	int		dir;

	dest = stack_index(a, value);
	dir = direction(a, value);
	while (index || dest)
	{
		if (index && dest && dir == OP_R && index-- && dest--)
		{
			ps_rr(a, b);
			continue ;
		}
		if (index && index--)
			ps_rx(b);
		if (dest)
		{
			if (dir == OP_R && dest--)
				ps_rx(a);
			else if (dir == OP_RR && dest++)
				ps_rrx(a);
		}
		if (dest == stack_size(a))
			dest = 0;
	}
}

// static void	align(t_stack *s, int n)
// {
// 	int	max;
// 	int	min;
// 	int	last;

// 	if (!s->items)
// 		return ;
// 	stack_max(s, &min, &max);
// 	while (s->items)
// 	{
// 		last = stack_last(s)->value;
// 		if (n < min && s->items->value == min)
// 			break ;
// 		if (n > max && s->items->value == max)
// 		{
// 			ps_rx(s);
// 			break ;
// 		}
// 		if (s->items->value > n && last < n)
// 			break ;
// 		ps_rx(s);
// 	}
// }

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
		// stack_print(a);
		// stack_print(b);
		stack_max(a, &min,&max);
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
