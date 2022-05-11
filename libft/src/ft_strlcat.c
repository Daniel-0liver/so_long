/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:16:32 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/08 21:07:06 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strlcat() function appends the NUL-terminated 
// string src to the end of dst.  It will append at most size -
// strlen(dst) - 1 bytes, NUL-terminating the result.

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	while (*src && i + 1 < size)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	if (i < size)
		dst[i] = '\0';
	return (i + ft_strlen(src));
}
// int main()
// {
// 	char dest[50] = "Hello ";
// 	char src[50] = "World2222222";

// 	// char dest1[50] = "Hello ";
// 	// char src1[50] = "World2222222";

// 	printf("%u\n", ft_strlcat(dest, src, 13));
// 	printf("%s\n", dest);
// 	// printf("%u\n", strlcat(dest1, src1, 5));
// 	// printf("%s\n", dest1);
// }