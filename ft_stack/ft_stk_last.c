/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:50:50 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 10:11:19 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

t_stk_item	*ft_stk_last(t_stack *stack)
{
	t_stk_item	*item;

	item = stack->items;
	while (item->next)
		item = item->next;
	return (item);
}
