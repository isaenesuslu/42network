#include "algo.h"
#include "ops.h"

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*curr_a;
	t_node	*target;
	long	match;

	while (b)
	{
		match = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < match)
			{
				match = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match == LONG_MAX)
			b->target_pos = find_min_pos(a);
		else
			b->target_pos = target->pos;
		b = b->next;
	}
}

static void	init_push(t_node **a, t_node **b)
{
	int	len;

	len = ps_get_size(*a);
	if (len-- > 3 && !ps_is_sorted(*a))
		pb(a, b, true);
	if (len-- > 3 && !ps_is_sorted(*a))
		pb(a, b, true);
	while (len-- > 3 && !ps_is_sorted(*a))
	{
		ps_set_positions(*a);
		ps_set_positions(*b);
		set_target_pos(*a, *b);
		ps_calc_cost(*a, *b);
		ps_exec_move(a, b);
	}
}

void	ps_sort_turk(t_node **a, t_node **b)
{
	init_push(a, b);
	sort_three(a);
	while (*b)
	{
		ps_set_positions(*a);
		ps_set_positions(*b);
		set_target_a(*a, *b);
		move_back_to_a(a, b);
	}
	ps_finalize_rotation(a);
}
