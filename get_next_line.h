/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 22:15:32 by iuslu             #+#    #+#             */
/*   Updated: 2026/03/11 14:25:57 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_buffer(char *s1, char *s2);
char	*ft_new_buffer(char **buff, int j);
char	*ft_bfr(char **buffer, int i);

#endif
