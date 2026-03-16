/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybalkan <ybalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:57:00 by ybalkan           #+#    #+#             */
/*   Updated: 2026/03/16 13:07:49 by ybalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_mode	ps_stack_init(t_node **stack_a, int argc, char **argv)
{
	return (ps_parse_input(argc, argv, stack_a));
}
