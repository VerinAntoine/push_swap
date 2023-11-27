/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:46:53 by averin            #+#    #+#             */
/*   Updated: 2023/11/27 07:48:25 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	stack_size(t_stack *s)
{
	t_stack_item	*item;
	size_t			i;

	item = s->items;
	i = 0;
	while (item)
	{
		item = item->next;
		i++;
	}
	return (i);
}
