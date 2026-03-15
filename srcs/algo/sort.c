#include "algo.h"
#include "ops.h"

void	sort_three(t_node **a)
{
	int	max;

	if (ps_is_sorted(*a))
		return ;
	max = find_max_val(*a);
	if ((*a)->value == max)
		ra(a, true);
	else if ((*a)->next->value == max)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

void	ps_sort_small(t_node **a, t_node **b)
{
	while (ps_get_size(*a) > 3 && !ps_is_sorted(*a))
		ps_push_cheapest_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b, true);
}
