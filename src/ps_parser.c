/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:36 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 09:04:33 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	if (ft_strlen(s) == 0)
		return (FALSE);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (FALSE);
		s++;
	}
	return (TRUE);
}

static int	is_in(t_stack *stack, int i)
{
	t_stack_item	*item;

	item = stack->items;
	if (!item)
		return (FALSE);
	while (item)
	{
		if (item->value == i)
			return (TRUE);
		item = item->next;
	}
	return (FALSE);
}

/**
 * @warning NULLABLE
*/
t_stack	*ps_parse(size_t n, char **args)
{
	t_stack	*stack;
	size_t	i;
	int		number;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (ft_printf("Error\n"), NULL);
	i = -1;
	while (++i < n)
	{
		number = ft_atoi(args[i]);
		if (!is_number(args[i]) || is_in(stack, number))
			return (ft_printf("Error\n"), stack_free(stack), NULL);
		stack_add(stack, number);
	}
	return (stack);
}
