/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:18:00 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:18:01 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_temp;
	unsigned char	*dest_temp;

	src_temp = (unsigned char *)src;
	dest_temp = (unsigned char *)dest;
	src_temp = src_temp + (n - 1);
	dest_temp = dest_temp + (n - 1);
	while (n > 0)
	{
		n--;
		*dest_temp = *src_temp;
		dest_temp--;
		src_temp--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n > 0)
	{
		if (dest > src)
			return (ft_rmove(dest, src, n));
		else if (src > dest)
			return (ft_memcpy(dest, src, n));
	}
	return (dest);
}
