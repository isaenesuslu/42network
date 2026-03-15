/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 15:08:52 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/15 15:56:17 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "ops.h"
#include "algo.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	check_args(argc, argv);
	init_stack(&a, argc, argv);
	if (!is_sorted(a))
	{
		if (stack_size(a) <= 5)
			sort(&a, &b);
		else
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
