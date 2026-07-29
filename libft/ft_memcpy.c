/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:17:52 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:17:53 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*src_temp;
	unsigned char		*dest_temp;

	src_temp = (unsigned const char *) src;
	dest_temp = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*dest_temp = *src_temp;
		dest_temp++;
		src_temp++;
		n--;
	}
	return (dest);
}
