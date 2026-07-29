/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:15:29 by iuslu             #+#    #+#             */
/*   Updated: 2026/03/11 14:58:39 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ct;

	ct = c;
	if (!s)
	{
		return (NULL);
	}
	while (*s)
	{
		if (*s == ct)
			return ((char *)s);
		s++;
	}
	if (*s == ct)
		return ((char *)s);
	return (NULL);
}

char	*ft_buffer(char *s1, char *s2)
{
	char	*s_new;
	char	*new_tmp;
	char	*s1_start;

	if (!s1)
	{
		s1 = (char *) malloc(1);
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	s1_start = s1;
	s_new = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_new)
		return (free(s1), NULL);
	new_tmp = s_new;
	while (*s1)
		*(s_new++) = *(s1++);
	while (*s2)
		*(s_new++) = *(s2++);
	*s_new = '\0';
	free(s1_start);
	return (new_tmp);
}

static char	*ft_new_buffer(char **buff, int j)
{
	char	*new_buff;
	char	*start_buff;
	char	*free_buff;

	new_buff = (char *) malloc(j + 1);
	if (!new_buff)
		return (NULL);
	start_buff = new_buff;
	free_buff = *buff;
	*buff = *buff + (ft_strlen(*buff) - j);
	while (j-- > 0)
	{
		*new_buff = **buff;
		new_buff++;
		(*buff)++;
	}
	*new_buff = '\0';
	free(free_buff);
	*buff = start_buff;
	return (start_buff);
}

char	*ft_bfr(char **buffer, int i)
{
	char	*new_buff;
	char	*return_buff;
	int		j;
	int		c;

	c = 0;
	j = (ft_strlen(*buffer) - i);
	new_buff = (char *) malloc(i + 1);
	if (!new_buff)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return_buff = new_buff;
	while (c < i)
		*(new_buff++) = (*buffer)[c++];
	*new_buff = '\0';
	if (!ft_new_buffer(buffer, j))
	{
		free(*buffer);
		*buffer = NULL;
		return (free(return_buff), NULL);
	}
	return (return_buff);
}
