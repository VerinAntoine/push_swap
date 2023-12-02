/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averin <averin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:57 by averin            #+#    #+#             */
/*   Updated: 2023/12/01 10:17:16 by averin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_stack.h"

void			ps_sx(t_stack *s);
void			ps_ss(t_stack *a, t_stack *b);
void			ps_px(t_stack *from, t_stack *to);
void			ps_rx(t_stack *s);
void			ps_rr(t_stack *a, t_stack *b);
void			ps_rrx(t_stack *s);
void			ps_rrr(t_stack *a, t_stack *b);

t_stack			*ps_parse(size_t n, char *args[]);
size_t			direction(t_stack *s, int n);
void			align(t_stack *a, t_stack *b, int value, size_t index);
void			ralign(t_stack *a, t_stack *b, int value, size_t index);
void			ps_cost(t_stack	*a, t_stack *b);
t_stack_item	*select_costless(t_stack *b);
void			dispatch_sort(t_stack *a, t_stack *b);
void			ps_presort(t_stack *a, t_stack *b);
void			ps_sort(t_stack *a, t_stack *b);
void			sort_two(t_stack *s);
void			sort_three(t_stack	*s);

#endif
