/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:21:23 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:21:24 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newplace;
	char			*placestart;
	unsigned int	i;

	i = 0;
	newplace = (char *) malloc(ft_strlen(s) + 1);
	if (!newplace)
		return (NULL);
	placestart = newplace;
	while (s[i])
	{
		*newplace = f(i, s[i]);
		i++;
		newplace++;
	}
	*newplace = '\0';
	return (placestart);
}
