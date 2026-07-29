/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:22:38 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/16 19:41:10 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long i);
int	ft_puthex(unsigned long i, char c);
int	ft_putptr(unsigned long i);

#endif
