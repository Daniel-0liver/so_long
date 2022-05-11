/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:24:40 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:12:46 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The bzero() function erases the data in the n bytes of the 
// memory starting at the location pointed to by s, by
// writing zeros (bytes containing '\0') to that area.

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main() {
// 	char *test = {"testando"};
// 	printf("%s\n", test);
// 	ft_bzero(test, 2);
// 	printf("%s\n", test);
// 	return 0;
// }