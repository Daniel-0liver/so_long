/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:35:47 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:24:56 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memcpy()  function  copies  n  bytes from memory area src to
// memory area dest. The memory areas must not overlap.

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((char *)(dest + i)) = *((char *)(src + i));
		i++;
	}
	return (dest);
}

// int main() {
// 	char test[] = "testing";
// 	char *ori = "testing";	
// 	char *testcpy = ft_memcpy(testcpy, test, 5);
// 	// char *orig = memcpy(orig, ori, 5);

// 	printf("Original: %s, copy: %s, \n", test, testcpy);
// 	// printf("Original: %s, copy: %s, \n", ori, orig);

// 	return 0;
// }
