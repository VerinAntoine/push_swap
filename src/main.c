/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:43:44 by averin            #+#    #+#             */
/*   Updated: 2023/11/27 13:56:59 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main()
// {
// 	t_stack *a = ft_calloc(1, sizeof(t_stack));
// 	t_stack *b = ft_calloc(1, sizeof(t_stack));
// 	a->name = 'a';
// 	b->name = 'b';

// 	stack_add(a, 2);
// 	stack_add(a, 4);
// 	stack_add(a, 6);
// 	stack_add(a, 8);

// 	stack_print(a);
// 	ps_rrx(a);
// 	stack_print(a);

// 	return 0;
// }


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	size_t	size;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_size_split(argv[1], ' ', &size);
		a = ps_parse(size, argv);
		ft_free_split(argv);
	}
	else
		a = ps_parse(argc - 1, argv + 1);
	
	if (!a) //TODO Rewrite
		return (0);
	b = ft_calloc(1, sizeof(t_stack));
	if (!b)
		return (ft_printf("Error\n"), stack_free(a), 0);
	a->name = 'a';
	b->name = 'b';
	ps_sort(a, b);
	// stack_print(a);
	// stack_print(b);
	return (stack_free(a), stack_free(b), 0);
}
