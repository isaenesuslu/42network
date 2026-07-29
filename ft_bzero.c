/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:14:21 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:14:23 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*stemp;

	stemp = (unsigned char *)s;
	while (n > 0)
	{
		*stemp = 0;
		stemp++;
		n--;
	}
}
