#ifndef ALGO_H
# define ALGO_H

# include "ps.h"

void	ps_sort_small(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	ps_sort_turk(t_node **stack_a, t_node **stack_b);

void	set_target_pos(t_node *a, t_node *b);
void	ps_calc_cost(t_node *a, t_node *b);
void	ps_exec_move(t_node **a, t_node **b);
void	apply_rotations(t_node **a, t_node **b, int cost_a, int cost_b);
void	move_back_to_a(t_node **a, t_node **b);
void	ps_push_cheapest_to_b(t_node **a, t_node **b);

int		find_max_val(t_node *stack);
int		find_min_pos(t_node *stack);
int		find_max_pos(t_node **stack);
void	ps_finalize_rotation(t_node **a);

#endif
