/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:21:50 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/05 16:35:46 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_max(const char *big, const char *little)
{
	const char	*bstart;
	const char	*lstart;

	lstart = little;
	while (*big)
	{
		bstart = big;
		while (*bstart == *lstart && *bstart)
		{
			bstart++;
			lstart++;
		}
		if (*lstart == '\0')
			return ((char *)big);
		lstart = little;
		big++;
	}
	return (NULL);
}

static char	*ft_isavailable(const char *big, const char *little, size_t len)
{
	const char	*lstart;
	const char	*bstart;
	const char	*endptr;

	lstart = little;
	if (len > ft_strlen(big))
		return (ft_max(big, little));
	bstart = big;
	endptr = big + len;
	while ((*big && *little) && big < endptr)
	{
		bstart = big;
		while (*bstart == *lstart && *bstart && bstart < endptr)
		{
			lstart++;
			bstart++;
		}
		if (*lstart == '\0')
			return ((char *)big);
		lstart = little;
		big++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (*little == '\0')
		return ((char *)big);
	if (len > 0)
	{
		return (ft_isavailable(big, little, len));
	}
	return (NULL);
}
