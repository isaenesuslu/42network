/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:22:00 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:22:01 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	const char		*st;
	unsigned char	ct;

	st = s;
	ct = c;
	if (*s == '\0' && ct != '\0')
		return (NULL);
	while (*s)
		s++;
	if (*s == ct)
		return ((char *)s);
	while (--s != st)
	{
		if (*s == ct)
			return ((char *)s);
	}
	if (*s == ct)
		return ((char *)s);
	return (NULL);
}
