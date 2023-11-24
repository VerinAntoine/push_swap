/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:41:30 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 09:44:34 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_stk_print(t_stack *stack)
{
	t_stack_item	*item;

	item = stack->items;
	ft_printf("stack %c: ", stack->name);
	while (item)
	{
		ft_putnbr_fd(item->value, 1);
		ft_putstr_fd(" ", 1);
		item = item->next;
	}
	ft_putstr_fd("\n", 1);
}
