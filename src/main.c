/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:43:44 by averin            #+#    #+#             */
/*   Updated: 2023/11/25 00:21:26 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = ps_parse(argc - 1, argv + 1);
	if (!a) //TODO Rewrite
		return (0);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		return (ft_printf("Error\n"), stack_free(a), 0);
	a->name = 'a';
	b->name = 'b';
	ps_sort(a, b);
	stack_print(a);
	stack_print(b);
	return (stack_free(a), stack_free(b), 0);
}
