
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
