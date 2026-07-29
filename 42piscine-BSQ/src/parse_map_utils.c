/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:46:25 by iuslu             #+#    #+#             */
/*   Updated: 2025/11/26 10:25:14 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	set_header_values(char *buf, int i, t_map *m)
{
	m->empty = buf[i - 3];
	m->obst = buf[i - 2];
	m->full = buf[i - 1];
	if (m->empty == m->obst)
		return (-1);
	if (m->empty == m->full)
		return (-1);
	if (m->obst == m->full)
		return (-1);
	return (0);
}
