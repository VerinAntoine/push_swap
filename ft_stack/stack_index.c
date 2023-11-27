/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:35:37 by averin            #+#    #+#             */
/*   Updated: 2023/11/27 07:46:22 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	stack_index(t_stack *s, int n)
{
	t_stack_item	*item;
	size_t			i;
	int				last;

	item = s->items;
	if (!item)
		return (0);
	last = item->value;
	i = 0;
	while (item)
	{
		if (item->value == n || (item->value > n && last < n))
			return (i);
		i++;
		item = item->next;
	}
	return (0);
}
