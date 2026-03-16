/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:49:25 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 14:08:26 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	sa(t_node **a, bool print, int *move_count)
{
	swap(a);
	if (print)
	{
		write(1, "sa\n", 3);
		if (move_count)
			(*move_count)++;
	}
}

void	sb(t_node **b, bool print, int *move_count)
{
	swap(b);
	if (print)
	{
		write(1, "sb\n", 3);
		if (move_count)
			(*move_count)++;
	}
}

void	ss(t_node **a, t_node **b, bool print, int *move_count)
{
	swap(a);
	swap(b);
	if (print)
	{
		write(1, "ss\n", 3);
		if (move_count)
			(*move_count)++;
	}
}
