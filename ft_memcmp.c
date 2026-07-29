/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:17:44 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:17:47 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	s1temp = (unsigned char *)s1;
	s2temp = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1temp > *s2temp)
			return (*s1temp - *s2temp);
		else if (*s1temp < *s2temp)
			return (*s1temp - *s2temp);
		s1temp++;
		s2temp++;
		n--;
	}
	return (0);
}
