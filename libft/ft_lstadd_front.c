/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:55:23 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:21:15 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the element ’new’ at the beginning of the list.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// int main()
// {
// 	t_list *my_tlist = (t_list *)malloc(sizeof(t_list) * 5);
// 	char content[20] = "CONTENT.";
// 	t_list *linked_list_item1 = ft_lstnew((void *)content);
// 	char content2[20] = "CONTENT2.";
// 	t_list *linked_list_item2 = ft_lstnew((void *)content2);
// 	ft_lstadd_front(&my_tlist, linked_list_item1);
// 	printf("The result is %s\n", (char *)my_tlist[0].content);
// 	printf("The result is %s\n", (char *)my_tlist[0].next->content);
// 	ft_lstadd_front(&my_tlist, linked_list_item2);
// 	printf("The result is %s\n", (char *)my_tlist[0].content);
// 	printf("The result is %s\n", (char *)my_tlist[0].next->content);
//  	return 0;
// }
