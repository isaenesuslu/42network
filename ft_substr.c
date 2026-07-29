/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:22:28 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:22:29 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_copymachine(char *subptr, char *start, size_t len)
{
	char	*subtemp;

	subtemp = subptr;
	while (len > 0)
	{
		*subptr = *start;
		subptr++;
		start++;
		len--;
	}
	*subptr = '\0';
	return (subtemp);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substart;
	char	*subptr;
	size_t	sublen;

	if (s)
	{
		sublen = ft_strlen(s);
		if (start > ft_strlen(s))
			return (ft_strdup(""));
		substart = (char *)s + start;
		sublen = ft_strlen(substart);
		if (len <= sublen)
		{
			subptr = (char *) malloc(len + 1);
			if (!subptr)
				return (NULL);
			return (ft_copymachine(subptr, substart, len));
		}
		else
			return (ft_strdup(substart));
	}
	return (NULL);
}
