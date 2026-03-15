#include "ps.h"

t_mode	ps_stack_init(t_node **stack_a, int argc, char **argv)
{
	return (ps_parse_input(argc, argv, stack_a));
}

