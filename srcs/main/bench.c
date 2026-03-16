/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:00:23 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 11:56:39 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "algo.h"
#include "ops.h"

void	ps_dispatch_sort(t_node **a, t_node **b, int size, int *move_count)
{
	if (size <= 5)
	{
		if (size == 2)
			sa(a, true, move_count);
		else if (size == 3)
			sort_three(a, move_count);
		else
			ps_sort_small(a, b, move_count);
	}
	else
		ps_sort_engine(a, b, move_count);
}

void	ps_print_bench(int n)
{
	char	buf[12];
	int		i;

	write(1, "Total moves: ", 13);
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i-- > 0)
		write(1, &buf[i], 1);
	write(1, "\n", 1);
}
