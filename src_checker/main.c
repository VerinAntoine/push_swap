/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:12:47 by antoine           #+#    #+#             */
/*   Updated: 2023/12/03 01:19:19 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dispatch_operation_next(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "ss", 3) == 0)
	{
		stack_swap(a);
		stack_swap(b);
		return (TRUE);
	}
	else if (ft_strncmp(op, "rr", 3) == 0)
	{
		stack_rotate(a);
		stack_rotate(b);
		return (TRUE);
	}
	else if (ft_strncmp(op, "rrr", 4) == 0)
	{
		stack_rvs_rotate(a);
		stack_rvs_rotate(b);
		return (TRUE);
	}
	return (FALSE);
}

static int	dispatch_operation(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		return (stack_swap(a), TRUE);
	else if (ft_strncmp(op, "sb", 3) == 0)
		return (stack_swap(b), TRUE);
	else if (ft_strncmp(op, "pa", 3) == 0)
		return (stack_push(b, a), TRUE);
	else if (ft_strncmp(op, "pb", 3) == 0)
		return (stack_push(a, b), TRUE);
	else if (ft_strncmp(op, "ra", 3) == 0)
		return (stack_rotate(a), TRUE);
	else if (ft_strncmp(op, "rb", 3) == 0)
		return (stack_rotate(b), TRUE);
	else if (ft_strncmp(op, "rra", 4) == 0)
		return (stack_rvs_rotate(a), TRUE);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		return (stack_rvs_rotate(b), TRUE);
	else
		return (dispatch_operation_next(a, b, op));
}

static int	perform_operations(t_stack *a, t_stack *b)
{
	char	*line;
	char	*trimmed;

	line = NULL;
	while (oget_next_line(0, &line))
	{
		trimmed = ft_strtrim(line, "\n");
		if (!trimmed)
			return (free(line), FALSE);
		if (!dispatch_operation(a, b, trimmed))
			return (free(line), free(trimmed), FALSE);
		free(trimmed);
	}
	if (stack_is_ordered(a) && stack_size(b) == 0)
		return (free(line), TRUE);
	return (free(line), FALSE);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	size_t	size;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (ft_dprintf(2, "Error\n"), 0);
		argv = ft_size_split(argv[1], ' ', &size);
		a = ps_parse(size, argv, 'a');
		ft_free_split(argv);
	}
	else
		a = ps_parse(argc - 1, argv + 1, 'a');
	if (!a)
		return (0);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		return (ft_dprintf(2, "Error\n"), stack_free(a), 0);
	b->name = 'b';
	if (perform_operations(a, b))
		return (ft_printf("OK\n"), stack_free(a), stack_free(b), 0);
	return (ft_dprintf(2, "KO\n"), stack_free(a), stack_free(b), 0);
}
