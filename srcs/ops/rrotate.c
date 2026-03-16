/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:49:21 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 11:58:14 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

extern int	g_move_count;

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ps_get_last(*stack); 
	last->prev->next = NULL;    
	last->next = *stack;        
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;              
}

void	rra(t_node **a, bool print)
{
	reverse_rotate(a);
	if (print)
	{
		write(1, "rra\n", 4);
		g_move_count++;
	}
}

void	rrb(t_node **b, bool print)
{
	reverse_rotate(b);
	if (print)
	{
		write(1, "rrb\n", 4);
		g_move_count++;
	}
}

void	rrr(t_node **a, t_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
	{
		write(1, "rrr\n", 4);
		g_move_count++;
	}
}
