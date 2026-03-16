/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 20:49:04 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 23:43:09 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "algo.h"
#include "ops.h"

t_mode	g_mode = MODE_ADAPTIVE;

static void	ps_parse_flags(int *argc, char ***argv, bool *bench)
{
	while (*argc > 1 && (*argv)[1][0] == '-')
	{
		if (ps_strcmp((*argv)[1], "--bench") == 0)
			*bench = true;
		else if (ps_strcmp((*argv)[1], "--simple") == 0)
			g_mode = MODE_SIMPLE;
		else if (ps_strcmp((*argv)[1], "--medium") == 0)
			g_mode = MODE_MEDIUM;
		else if (ps_strcmp((*argv)[1], "--complex") == 0)
			g_mode = MODE_COMPLEX;
		else if (ps_strcmp((*argv)[1], "--adaptive") == 0)
			g_mode = MODE_ADAPTIVE;
		else
			break ;
		(*argc)--;
		(*argv)++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	bool	bench;
	int		move_count;

	a = NULL;
	b = NULL;
	bench = false;
	move_count = 0;
	if (argc < 2)
		return (0);
	ps_parse_flags(&argc, &argv, &bench);
	ps_stack_init(&a, argc, argv);
	if (!a || ps_is_sorted(a))
	{
		ps_free_all(&a);
		return (0);
	}
	ps_dispatch_sort(&a, &b, ps_get_size(a), &move_count);
	if (bench)
		ps_print_bench(move_count);
	ps_free_all(&a);
	return (0);
}
