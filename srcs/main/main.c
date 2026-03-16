/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:49:04 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 12:44:11 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "algo.h"
#include "ops.h"

extern int	g_move_count;

static void	ps_parse_bench(int *argc, char ***argv, bool *bench)
{
	if (ps_strcmp((*argv)[1], "--bench") == 0)
	{
		*bench = true;
		(*argc)--;
		(*argv)++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	bool	bench;

	a = NULL;
	b = NULL;
	bench = false;
	g_move_count = 0;
	if (argc < 2)
		return (0);
	ps_parse_bench(&argc, &argv, &bench);
	ps_stack_init(&a, argc, argv);
	if (!a || ps_is_sorted(a))
	{
		ps_free_all(&a);
		return (0);
	}
	ps_dispatch_sort(&a, &b, ps_get_size(a));
	if (bench)
		ps_print_bench(g_move_count);
	ps_free_all(&a);
	return (0);
}
