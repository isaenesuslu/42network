#include "algo.h"
#include "ops.h"

void	set_target_pos(t_node *a, t_node *b)
{
	t_node	*curr_b;
	t_node	*target;
	long	match;

	while (a)
	{
		match = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > match)
			{
				match = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match == LONG_MIN)
			a->target_pos = find_max_pos(&b);
		else
			a->target_pos = target->pos;
		a = a->next;
	}
}

void	ps_calc_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = ps_get_size(a);
	len_b = ps_get_size(b);
	while (a)
	{
		a->cost_a = a->pos;
		if (a->pos > len_a / 2)
			a->cost_a = (len_a - a->pos) * -1;
		a->cost_b = a->target_pos;
		if (a->target_pos > len_b / 2)
			a->cost_b = (len_b - a->target_pos) * -1;
		a = a->next;
	}
}

void	ps_exec_move(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*cheapest;
	int		min_val;
	int		total;

	tmp = *a;
	min_val = INT_MAX;
	while (tmp)
	{
		if ((tmp->cost_a >= 0 && tmp->cost_b >= 0)
			|| (tmp->cost_a <= 0 && tmp->cost_b <= 0))
			total = (abs(tmp->cost_a) > abs(tmp->cost_b)) ? abs(tmp->cost_a)
				: abs(tmp->cost_b);
		else
			total = abs(tmp->cost_a) + abs(tmp->cost_b);
		if (total < min_val)
		{
			min_val = total;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	apply_rotations(a, b, cheapest->cost_a, cheapest->cost_b);
	pb(a, b, true);
}
