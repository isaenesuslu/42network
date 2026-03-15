#include "ps.h"
#include "ops.h"
#include "algo.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	check_args(argc, argv);
	init_stack(&a, argc, argv);
	if (!is_sorted(a))
	{
		if (stack_size(a) <= 5)
			sort_tiny(&a, &b);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
