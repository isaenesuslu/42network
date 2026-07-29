/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:16:21 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:16:22 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_result(int n, int ntemp, char *itoaptr, int mallocspace)
{
	itoaptr--;
	while (mallocspace > 0)
	{
		*itoaptr = (n % 10) + '0';
		n = (n / 10);
		mallocspace--;
		itoaptr--;
	}
	if (ntemp < 0)
		*itoaptr = '-';
	return (itoaptr);
}

static char	*ft_calculator(int n, int mallocspace)
{
	char	*itoaptr;
	char	*itoastart;
	int		ntemp;

	ntemp = n;
	if (n < 0)
	{
		itoaptr = (char *) malloc(mallocspace + 2);
		if (!itoaptr)
			return (NULL);
		itoastart = itoaptr;
		itoaptr = itoaptr + (mallocspace + 1);
		n = n * -1;
	}
	else
	{
		itoaptr = (char *) malloc(mallocspace + 1);
		if (!itoaptr)
			return (NULL);
		itoastart = itoaptr;
		itoaptr = itoaptr + mallocspace;
	}
	*itoaptr = '\0';
	ft_result(n, ntemp, itoaptr, mallocspace);
	return (itoastart);
}

char	*ft_itoa(int n)
{
	int		ntemp;
	int		mallocspace;

	mallocspace = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		ntemp = n * -1;
	else
		ntemp = n;
	while (ntemp > 0)
	{
		ntemp = (ntemp / 10);
		mallocspace++;
	}
	return (ft_calculator(n, mallocspace));
}
