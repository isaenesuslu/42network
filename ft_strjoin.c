/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:20:04 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:20:05 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_join(char const *s1, char const *s2, char *snew)
{
	char	*snewtemp;

	snewtemp = snew;
	while (*s1)
	{
		*snew = *s1;
		s1++;
		snew++;
	}
	while (*s2)
	{
		*snew = *s2;
		s2++;
		snew++;
	}
	*snew = '\0';
	return (snewtemp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	int		s1len;
	int		s2len;

	if (s1 && s2)
	{
		s1len = ft_strlen(s1);
		s2len = ft_strlen(s2);
		snew = (char *) malloc((s1len + s2len) + 1);
		if (!snew)
			return (NULL);
		return (ft_join(s1, s2, snew));
	}
	return (NULL);
}
