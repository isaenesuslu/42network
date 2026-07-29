/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:14:04 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:14:05 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_result(const char *strtemp)
{
	int	result;

	result = 0;
	while (*strtemp >= 48 && *strtemp <= 57)
	{
		result = (result * 10) + (*strtemp - '0');
		strtemp++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	counter;
	int	result;

	sign = 1;
	counter = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == 43 || *str == 45)
	{
		if (counter == 1)
			return (0);
		if (*str == 45)
			sign *= -1;
		counter++;
		str++;
	}
	result = (ft_result(str) * sign);
	return (result);
}
