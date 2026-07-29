/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuslu <iuslu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 09:16:31 by iuslu             #+#    #+#             */
/*   Updated: 2026/02/04 09:16:32 by iuslu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		temp = *lst;
		while (temp)
		{
			if (temp->next == NULL)
			{
				temp->next = new;
				return ;
			}
			temp = temp->next;
		}
	}
}
