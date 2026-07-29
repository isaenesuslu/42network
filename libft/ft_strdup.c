/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:19:29 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:19:30 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	unsigned char	*ptr;
	unsigned char	*start;
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	ptr = (unsigned char *) malloc(i + 1);
	if (ptr)
	{
		start = ptr;
		while (*s)
		{
			*ptr = *s;
			ptr++;
			s++;
		}
		*ptr = '\0';
		return ((char *)start);
	}
	else
		return (NULL);
}
