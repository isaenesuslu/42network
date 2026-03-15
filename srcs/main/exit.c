#include "ps.h"

void	ps_free_all(t_node **stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	ps_error_exit(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
		ps_free_all(stack_a);
	if (stack_b)
		ps_free_all(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
