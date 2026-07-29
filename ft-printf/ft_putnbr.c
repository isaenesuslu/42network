/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:14:57 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/18 19:31:02 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long i)
{
	int	counter;

	counter = 0;
	if (i < 0)
	{
		counter += ft_putchar('-');
		i *= -1;
		counter += ft_putnbr(i);
	}
	else if (i > 9)
	{
		counter += ft_putnbr(i / 10);
		counter += ft_putnbr(i % 10);
	}
	else
	{
		counter += ft_putchar(i + 48);
	}
	return (counter);
}
