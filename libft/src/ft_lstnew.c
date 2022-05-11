/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:22:32 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/05 19:39:56 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new
// element. The variable ’content’ is initialized
// with the value of the parameter ’content’. The
// variable ’next’ is initialized to NULL.

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
