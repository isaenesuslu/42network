/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:48:34 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/17 13:01:16 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include "ps.h"

void	sa(t_node **stack_a, bool print, int *move_count);
void	sb(t_node **stack_b, bool print, int *move_count);
void	ss(t_node **stack_a, t_node **stack_b, bool print, int *move_count);

void	pa(t_node **stack_a, t_node **stack_b, bool print, int *move_count);
void	pb(t_node **stack_a, t_node **stack_b, bool print, int *move_count);

void	ra(t_node **stack_a, bool print, int *move_count);
void	rb(t_node **stack_b, bool print, int *move_count);
void	rr(t_node **stack_a, t_node **stack_b, bool print, int *move_count);

void	rra(t_node **stack_a, bool print, int *move_count);
void	rrb(t_node **stack_b, bool print, int *move_count);
void	rrr(t_node **stack_a, t_node **stack_b, bool print, int *move_count);

#endif
