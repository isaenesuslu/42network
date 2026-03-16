/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:26:00 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 11:57:02 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ps_push_cheapest_to_b(t_node **a, t_node **b)
{
	int	min_pos;
	int	size;

	size = ps_get_size(*a);
	min_pos = find_min_pos(*a);
	if (min_pos > size / 2)
	{
		while (min_pos++ < size)
			rra(a, true);
	}
	else
	{
		while (min_pos-- > 0)
			ra(a, true);
	}
	pb(a, b, true);
}
