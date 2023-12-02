/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 10:25:00 by antoine           #+#    #+#             */
/*   Updated: 2023/12/02 23:05:06 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ralign_content(t_stack *a, size_t *dest, int dir)
{
	if (*dest)
	{
		if (dir == OP_R && (*dest)--)
			ps_rx(a);
		else if (dir == OP_RR && (*dest)++)
			ps_rrx(a);
	}
}

void	ps_ralign(t_stack *a, t_stack *b, int value, size_t index)
{
	size_t	dest;
	int		dir;

	dest = stack_index(a, value);
	dir = ps_direction(a, value);
	while (index || dest)
	{
		if (index && dest && dir == OP_RR && index++ && dest++)
			ps_rrr(a, b);
		else
		{
			if (index && index++)
				ps_rrx(b);
			ralign_content(a, &dest, dir);
		}
		if (index == stack_size(b))
			index = 0;
		if (dest == stack_size(a))
			dest = 0;
	}
}

void	ps_align(t_stack *a, t_stack *b, int value, size_t index)
{
	size_t	dest;
	int		dir;

	dest = stack_index(a, value);
	dir = ps_direction(a, value);
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
