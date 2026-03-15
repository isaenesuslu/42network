/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:08:21 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/15 15:59:40 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "ps.h"

/* Sıralama (srcs/algo/sort.c) */
void	sort(t_node **stack_a, t_node **stack_b);

/* Turk Algoritması (srcs/algo/turk.c) */
void	turk_sort(t_node **stack_a, t_node **stack_b);

/* Maliyet Hesapları (srcs/algo/cost.c) */
void	calculate_costs(t_node *stack_a, t_node *stack_b);

#endif
