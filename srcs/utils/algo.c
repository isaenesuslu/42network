#include "algo.h"
#include "ops.h"

int	find_max_pos(t_node **stack)
{
	t_node	*tmp;
	int		max_val;
	int		max_pos;
	int		curr_pos;

	tmp = *stack;
	max_val = INT_MIN;
	max_pos = 0;
	curr_pos = 0;
	while (tmp)
	{
		if (tmp->value > max_val)
		{
			max_val = tmp->value;
			max_pos = curr_pos;
		}
		tmp = tmp->next;
		curr_pos++;
	}
	return (max_pos);
}

int	find_max_val(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min_pos(t_node *stack)
{
	int		min_val;
	int		min_pos;
	int		curr_pos;

	min_val = stack->value;
	min_pos = 0;
	curr_pos = 0;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = curr_pos;
		}
		stack = stack->next;
		curr_pos++;
	}
	return (min_pos);
}

void	ps_finalize_rotation(t_node **a)
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
}

int	ps_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

