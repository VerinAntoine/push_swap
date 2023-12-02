/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:57:29 by averin            #+#    #+#             */
/*   Updated: 2023/11/24 20:59:46 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rx(t_stack *s)
{
	stack_rotate(s);
	ft_printf("r%c\n", s->name);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	ft_printf("rr\n");
}

void	ps_rrx(t_stack *s)
{
	stack_rvs_rotate(s);
	ft_printf("rr%c\n", s->name);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	stack_rvs_rotate(a);
	stack_rvs_rotate(b);
	ft_printf("rrr\n");
}
