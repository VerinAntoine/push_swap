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

static void	align(t_stack *s, int n)
{

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
	}
}
