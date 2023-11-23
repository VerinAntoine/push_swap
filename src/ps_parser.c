/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:36 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:53:51 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	if (ft_strlen(s) == 0)
		return (FALSE);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (FALSE);
		s++;
	}
	return (TRUE);
}

/**
 * Parse arguments to a stack
 * @warning NULLABLE
*/
t_stack	*ps_parse(int n, char **args)
{
	t_stack	*stack;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (ft_printf("Error\n"), NULL);
	i = -1;
	while (++i < n)
	{
		if (!is_number(args[i]))
			return (ft_printf("Error\n"), ft_stk_free(stack), NULL);
		ft_stk_add(stack, ft_atoi(args[i]));
	}
	return (stack);
}
