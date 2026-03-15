#include "ops.h"

static void	swap(t_node **stack)
{
	int	tmp_val;
	int	tmp_idx;

	if (!*stack || !(*stack)->next)
		return ;

	tmp_val = (*stack)->value;
	tmp_idx = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = tmp_val;
	(*stack)->next->index = tmp_idx;
}

void	sa(t_node **a, bool print)
{
	swap(a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, bool print)
{
	swap(b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
