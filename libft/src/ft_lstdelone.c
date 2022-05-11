/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 01:49:23 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/06 02:21:44 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter an element and frees the
// memory of the element’s content using the function
// ’del’ given as a parameter and free the element.
// The memory of ’next’ must not be freed.

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}
