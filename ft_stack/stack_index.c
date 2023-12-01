/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:35:37 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 14:31:37 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	stack_index(t_stack *s, int n)
{
	t_stack_item	*item;
	size_t			i;
	int				last;
	int				min;
	int				max;

	item = s->items;
	if (!item)
		return (0);
	stack_max(s, &min, &max);
	n = ft_min(n, max);
	n = ft_max(n, min);
	last = stack_last(s)->value;
	i = 0;
	while (item)
	{
		if (item->value == n || (item->value > n && last < n))
			return (i);
		i++;
		last = item->value;
		item = item->next;
	}
	return (0);
}
