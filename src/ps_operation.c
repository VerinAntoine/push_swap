/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:41:33 by averin            #+#    #+#             */
/*   Updated: 2023/11/24 20:56:31 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sx(t_stack *s)
{
	stack_swap(s);
	ft_printf("s%c\n", s->name);
}

void	ps_ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	ft_printf("ss");
}

void	ps_px(t_stack *from, t_stack *to)
{
	stack_push(from, to);
	ft_printf("p%c\n", to->name);
}
