/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:19:22 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:19:23 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ct;

	ct = c;
	while (*s)
	{
		if (*s == ct)
			return ((char *)s);
		s++;
	}
	if (*s == ct)
		return ((char *)s);
	return (NULL);
}
