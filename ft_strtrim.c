/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:22:21 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:22:22 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_mallocstr(const char *start, const char *end)
{
	char		*result;
	char		*resultr;
	int			len;

	result = (char *) malloc((end - start) + 1);
	if (!result)
		return (NULL);
	resultr = result;
	len = end - start;
	while (len > 0)
	{
		*result = *start;
		result++;
		start++;
		len--;
	}
	*result = '\0';
	return (resultr);
}

static char	*ft_cutpart(const char *s1, const char *s1start, const char *set)
{
	const char	*settemp;
	const char	*orgs1;
	int			counter;

	orgs1 = s1;
	s1 = (s1 + (ft_strlen(s1) - 1));
	while (s1 >= orgs1)
	{
		settemp = set;
		counter = 0;
		while (*settemp)
		{
			if (*settemp == *s1)
				counter = 1;
			settemp++;
		}
		if (counter == 1)
			s1--;
		else
			return (ft_mallocstr(s1start, s1 + 1));
	}
	return (ft_strdup(""));
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*settemp;
	const char	*s1temp;
	int			counter;

	s1temp = s1;
	if (s1temp && set)
	{
		while (*s1temp)
		{
			settemp = set;
			counter = 0;
			while (*settemp)
			{
				if (*settemp == *s1temp)
					counter = 1;
				settemp++;
			}
			if (counter == 1)
				s1temp++;
			else
				return (ft_cutpart(s1, s1temp, set));
		}
		return (ft_strdup(""));
	}
	return (NULL);
}
