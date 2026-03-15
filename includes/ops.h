/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:08:26 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/15 15:08:27 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "ps.h"

/* Swap (srcs/ops/swap.c) */
void	sa(t_node **stack_a, bool print);
void	sb(t_node **stack_b, bool print);
void	ss(t_node **stack_a, t_node **stack_b, bool print);

/* Push (srcs/ops/push.c) */
void	pa(t_node **stack_a, t_node **stack_b, bool print);
void	pb(t_node **stack_a, t_node **stack_b, bool print);

/* Rotate (srcs/ops/rotate.c) */
void	ra(t_node **stack_a, bool print);
void	rb(t_node **stack_b, bool print);
void	rr(t_node **stack_a, t_node **stack_b, bool print);

/* Reverse Rotate (srcs/ops/rrotate.c) */
void	rra(t_node **stack_a, bool print);
void	rrb(t_node **stack_b, bool print);
void	rrr(t_node **stack_a, t_node **stack_b, bool print);

#endif
