/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:43:44 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 16:54:21 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (!stack_is_ordered(a))
		ps_dispatch_sort(a, b);
	return (stack_free(a), stack_free(b), 0);
}
