/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:14:54 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/18 12:35:31 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_ptrcall(unsigned long nbr2)
{
	char	*hexbase;
	int		cnt;

	cnt = 0;
	hexbase = "0123456789abcdef";
	if (nbr2 > 0)
	{
		cnt += ft_ptrcall(nbr2 / 16);
		cnt += write(1, &hexbase[nbr2 % 16], 1);
	}
	return (cnt);
}

int	ft_putptr(unsigned long nbr)
{
	int	cnt;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	cnt = 0;
	cnt += write(1, "0x", 2);
	cnt += ft_ptrcall(nbr);
	return (cnt);
}
