/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:34:45 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:22:33 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memchr()  function scans the initial n bytes of the memory 
// area pointed to by s for the first instance of
// c.  Both c and the bytes of the memory area pointed to by s are 
// interpreted as unsigned char.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s + i)) == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (0);
}

// int main() {
// 	char example[] = "Testing";

// 	printf("%s\n", memchr(example, 'i', 5));
// 	printf("%s\n", ft_memchr(example, 'i', 5));

// 	return 0;
// }