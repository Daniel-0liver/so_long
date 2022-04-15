/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:50:30 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:25:45 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memmove() function copies n bytes from memory area src to 
// memory area dest.  The memory areas may overlap:
// copying takes place as though the bytes in src are first copied 
// into a temporary array that does  not  overlap
// src or dest, and the bytes are then copied from the temporary array to dest.

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		tmp_dst = (char *)dst;
		tmp_src = (char *)src;
		while (len--)
			*(tmp_dst + len) = *(tmp_src + len);
	}
	return (dst);
}

// int main() {
// 	// char *test = "testing";
// 	char *ori = "testing another";	
// 	// char *testcpy = ft_memcpy(testcpy, test, 5);
// 	memmove("orig", ori, 2);

// 	// printf("Original: %s, copy: %s, \n", test, testcpy);
// 	printf("Original: %s\nCopy:  \n", ori);

// 	return 0;
// }