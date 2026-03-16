/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:48:31 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 12:02:17 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "ps.h"

/* Sorting Algorithms */
void	ps_sort_small(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	ps_sort_engine(t_node **stack_a, t_node **stack_b);

/* Algorithm Utilities */
void	ps_set_rank_indices(t_node *stack);
void	ps_push_cheapest_to_b(t_node **a, t_node **b);
void	ps_finalize_rotation(t_node **a);
int		find_max_val(t_node *stack);
int		find_min_pos(t_node *stack);
int		find_max_pos(t_node **stack);

#endif
