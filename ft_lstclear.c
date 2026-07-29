/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:16:39 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:16:40 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (lst && del)
	{
		temp = *lst;
		while (temp)
		{
			temp2 = temp;
			temp = temp->next;
			del(temp2->content);
			free(temp2);
		}
		*lst = NULL;
	}
}
