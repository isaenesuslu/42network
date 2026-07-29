/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:21:33 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:21:34 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n > 0)
	{
		while ((*s1 == *s2) && n > 0 && (*s1 != '\0' && *s2 != '\0'))
		{
			s1++;
			s2++;
			n--;
		}
		if (*s1 != *s2 && n != 0)
			return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
