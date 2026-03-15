#include "ps.h"
#include "algo.h"
#include "ops.h"

static void	ps_dispatch_sort(t_node **a, t_node **b, t_mode mode, int size)
{
	if (mode == MODE_SIMPLE || (mode == MODE_ADAPTIVE && size <= 5))
	{
		if (size == 2)
			sa(a, true);
		else if (size == 3)
			sort_three(a);
		else
			ps_sort_small(a, b);
	}
	else
		ps_sort_turk(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_mode	mode;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	mode = ps_stack_init(&a, argc, argv);
	if (ps_is_sorted(a))
	{
		ps_free_all(&a);
		return (0);
	}
	ps_dispatch_sort(&a, &b, mode, ps_get_size(a));
	ps_free_all(&a);
	return (0);
}

