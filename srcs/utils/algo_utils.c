#include "algo.h"
#include "ops.h"

void	apply_rotations(t_node **a, t_node **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a-- > 0 && cost_b-- > 0)
			rr(a, b, true);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a++ < 0 && cost_b++ < 0)
			rrr(a, b, true);
	}
	while (cost_a > 0 && cost_a--)
		ra(a, true);
	while (cost_a < 0 && cost_a++)
		rra(a, true);
	while (cost_b > 0 && cost_b--)
		rb(b, true);
	while (cost_b < 0 && cost_b++)
		rrb(b, true);
}

void	ps_push_cheapest_to_b(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	size = ps_get_size(*a);
	min_pos = find_min_pos(*a);
	if (min_pos > size / 2)
		while (min_pos++ < size)
			rra(a, true);
	else
		while (min_pos-- > 0)
			ra(a, true);
	pb(a, b, true);
}

void	move_back_to_a(t_node **a, t_node **b)
{
	int	target_pos;
	int	size_a;

	size_a = ps_get_size(*a);
	target_pos = (*b)->target_pos;
	if (target_pos > size_a / 2)
		while (target_pos++ < size_a)
			rra(a, true);
	else
		while (target_pos-- > 0)
			ra(a, true);
	pa(a, b, true);
}
