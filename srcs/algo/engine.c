/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:56:00 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 11:55:09 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "ops.h"

static void	push_to_b_butterfly(t_node **a, t_node **b, int size,
				int *move_count)
{
	int	counter;
	int	chunk;

	counter = 0;
	if (size <= 100)
		chunk = 15;
	else
		chunk = 35;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b, true, move_count);
			rb(b, true, move_count);
			counter++;
		}
		else if ((*a)->index <= counter + chunk)
		{
			pb(a, b, true, move_count);
			counter++;
		}
		else
			ra(a, true, move_count);
	}
}

static void	push_back_to_a(t_node **a, t_node **b, int *move_count)
{
	int	size;
	int	max_pos;

	while (*b)
	{
		size = ps_get_size(*b);
		max_pos = find_max_pos(b);
		if (max_pos <= size / 2)
		{
			while (max_pos--)
				rb(b, true, move_count);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b, true, move_count);
		}
		pa(a, b, true, move_count);
	}
}

void	ps_sort_engine(t_node **a, t_node **b, int *move_count)
{
	int	size;

	size = ps_get_size(*a);
	ps_set_rank_indices(*a);
	push_to_b_butterfly(a, b, size, move_count);
	push_back_to_a(a, b, move_count);
}
