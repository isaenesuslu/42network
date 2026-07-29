/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:14:59 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/18 12:42:48 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_hexcal(unsigned long n, char c)
{
	char	*hexbasel;
	char	*hexbaseu;
	int		counter;

	counter = 0;
	hexbasel = "0123456789abcdef";
	hexbaseu = "0123456789ABCDEF";
	if (c == 'x' && n > 0)
	{
		counter += ft_hexcal(n / 16, c);
		counter += write(1, &hexbasel[n % 16], 1);
	}
	else if (c == 'X' && n > 0)
	{
		counter += ft_hexcal(n / 16, c);
		counter += write(1, &hexbaseu[n % 16], 1);
	}
	return (counter);
}

int	ft_puthex(unsigned long n, char c)
{
	int	counter;

	counter = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	counter = ft_hexcal(n, c);
	return (counter);
}
