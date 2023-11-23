/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:43:44 by averin            #+#    #+#             */
/*   Updated: 2023/11/23 13:58:22 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc == 1)
		return (0);
	a = ps_parse(argc - 1, argv + 1);
	if (!a)
		return (0);
	ft_stk_print(a);
	return (ft_stk_free(a), 0);
}
