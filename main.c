/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:42:37 by averin            #+#    #+#             */
/*   Updated: 2023/11/21 10:20:14 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "libft.h"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	t_stack *stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->name = 'a';
	ft_stk_add(stack, 1);
	ft_stk_add(stack, 2);
	ft_stk_add(stack, 3);
	ft_stk_add(stack, 4);
	ft_stk_print(stack);
	ft_stk_free(stack);
	return 0;
}
