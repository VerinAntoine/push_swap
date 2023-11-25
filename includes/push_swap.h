/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:32:57 by averin            #+#    #+#             */
/*   Updated: 2023/11/25 00:16:05 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_stack.h"

void	ps_sx(t_stack *s);
void	ps_ss(t_stack *a, t_stack *b);
void	ps_px(t_stack *from, t_stack *to);
void	ps_rx(t_stack *s);
void	ps_rr(t_stack *a, t_stack *b);
void	ps_rrx(t_stack *s);
void	ps_rrr(t_stack *a, t_stack *b);

t_stack	*ps_parse(int n, char *args[]);
void	ps_sort(t_stack *a, t_stack *b);

#endif
