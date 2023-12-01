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

// int main()
// {
// 	t_stack	*a;
// 	t_stack	*b;

// 	a = ft_calloc(1, sizeof(t_stack));
// 	b = ft_calloc(1, sizeof(t_stack));
// 	stack_add(a, 13);
// 	stack_add(a, 15);
// 	stack_add(a, 17);
// 	stack_add(a, 22);
// 	stack_add(a, 23);
// 	stack_add(a, 24);
// 	stack_add(b, 18);
// 	stack_add(b, 14);
// 	stack_add(b, 20);
// 	ps_sort(a, b);
// 	stack_print(a);
// 	stack_print(b);
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
		return (ft_dprintf(2, "Error\n"), stack_free(a), 0);
	a->name = 'a';
	b->name = 'b';
	if (stack_is_ordered(a))
		return (stack_free(a), stack_free(b), 0);
	dispatch_sort(a, b);
	return (stack_free(a), stack_free(b), 0);
}
