/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:17:34 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:17:35 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*stemp;

	stemp = (unsigned const char *)s;
	while (n > 0)
	{
		if (*stemp == (unsigned const char)c)
			return ((void *)stemp);
		stemp++;
		n--;
	}
	return (NULL);
}
