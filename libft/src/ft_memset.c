/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:37:47 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:26:20 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memset() function fills the first n bytes of the memory area 
// pointed to by s with the constant byte c.

void	*ft_memset(void *s, int c, size_t n)
{
	char	*t;

	t = s;
	while (n--)
	{
		*t++ = (char)c;
	}
	return (s);
}

// int main(void) {
//     char test[50] = {"testando"};
//     char test2[50] = {"testando"};
//     memset(test + 2, '*', 2);
//     ft_memset(test2 + 2, '*', 2);
//     printf("Teste ft_memset, %s\n", test);
//     printf("Teste ft_memset2, %s\n", test2);
//     return 0;
// }