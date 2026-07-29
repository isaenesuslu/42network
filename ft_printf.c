/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:22:47 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/18 19:31:17 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_fcontrol(const char *s, va_list args)
{
	if (*(s + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*(s + 1) == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*(s + 1) == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*(s + 1) == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (*(s + 1) == 'x' || *(s + 1) == 'X')
		return (ft_puthex(va_arg(args, unsigned int), *(s + 1)));
	else if (*(s + 1) == '%')
		return (write(1, "%", 1));
	else
		return (write(1, s, 2));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		check;

	check = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			check += ft_fcontrol(s, args);
			s += 2;
		}
		else if (*s == '%' && !*(s + 1))
			s++;
		else
		{
			write(1, s, 1);
			s++;
			check++;
		}
	}
	va_end(args);
	return (check);
}
