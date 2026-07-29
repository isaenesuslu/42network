/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:15:26 by iuslu             #+#    #+#             */
/*   Updated: 2026/03/11 14:26:08 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	static char	*buffer[1024];
	char		*tmp;
	int			i;

	tmp = (char *) malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (ft_clear(&buffer[fd], tmp));
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (ft_clear(&buffer[fd], tmp));
	i = 1;
	if (ft_strchr(buffer[fd], '\n'))
		return (ft_router(&buffer[fd], tmp));
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (ft_clear(&buffer[fd], tmp));
		tmp[i] = '\0';
		buffer[fd] = ft_buffer(buffer[fd], tmp);
		if (buffer[fd] == NULL)
			return (ft_clear(&buffer[fd], tmp));
		if (ft_strchr(buffer[fd], '\n'))
			return (ft_router(&buffer[fd], tmp));
	}
	return (ft_check(&buffer[fd], tmp));
}
