/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:49:19 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 13:16:36 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "ops.h"

extern int	g_move_count;

static void	rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ps_get_last(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

void	ra(t_node **a, bool print)
{
	rotate(a);
	if (print)
	{
		write(1, "ra\n", 3);
		g_move_count++;
	}
}

void	rb(t_node **b, bool print)
{
	rotate(b);
	if (print)
	{
		write(1, "rb\n", 3);
		g_move_count++;
	}
}

void	rr(t_node **a, t_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
	{
		write(1, "rr\n", 3);
		g_move_count++;
	}
}
