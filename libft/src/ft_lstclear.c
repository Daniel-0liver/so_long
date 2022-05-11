/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 02:00:01 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:21:27 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given element and every
// successor of that element, using the function ’del’ and free(3).
// Finally, the pointer to the list must be set to NULL.

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_list;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp_list = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp_list, del);
	}
	free(*lst);
	*lst = NULL;
}
