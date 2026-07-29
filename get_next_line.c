/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:15:26 by iuslu             #+#    #+#             */
/*   Updated: 2026/03/11 15:06:20 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_clear(char **buff, char *tmp)
{
	if (*buff)
	{
		free(*buff);
	}
	free(tmp);
	*buff = NULL;
	return (NULL);
}

char	*ft_check(char **buff, char *tmp)
{
	char	*return_buff;

	if (!buff || !*buff)
	{
		free(tmp);
		return (NULL);
	}
	else if (**buff == '\0')
		return (ft_clear(buff, tmp));
	else if (**buff != '\0')
	{
		return_buff = *buff;
		*buff = NULL;
		free(tmp);
		return (return_buff);
	}
	return (NULL);
}

char	*ft_router(char **buff, char *tmp)
{
	free(tmp);
	return (ft_bfr(buff, (ft_strchr(*buff, '\n') - *buff + 1)));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	int			i;

	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (ft_clear(&buffer, tmp));
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_clear(&buffer, tmp));
	i = 1;
	if (ft_strchr(buffer, '\n'))
		return (ft_router(&buffer, tmp));
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (ft_clear(&buffer, tmp));
		tmp[i] = '\0';
		buffer = ft_buffer(buffer, tmp);
		if (buffer == NULL)
			return (ft_clear(&buffer, tmp));
		if (ft_strchr(buffer, '\n'))
			return (ft_router(&buffer, tmp));
	}
	return (ft_check(&buffer, tmp));
}
