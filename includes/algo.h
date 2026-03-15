/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:08:21 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/15 15:08:22 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "ps.h"

/* Sıralama (srcs/algo/sort.c) */
void	sort_tiny(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);

/* Turk Algoritması (srcs/algo/turk.c) */
void	turk_sort(t_node **stack_a, t_node **stack_b);

/* Maliyet Hesapları (srcs/algo/cost.c) */
void	calculate_costs(t_node *stack_a, t_node *stack_b);
void	execute_cheapest_move(t_node **stack_a, t_node **stack_b);

#endif
