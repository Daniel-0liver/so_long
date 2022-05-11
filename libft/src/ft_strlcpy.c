/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:29:56 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:29:55 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strlcpy() function copies up to size - 1 characters from the 
// NUL-terminated string src to dst, NUL-terminat‐ ing the result.

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
// int main() {
// 	char test[] = "testing";
// 	char testcpy[100];
// 	size_t i = ft_strlcpy(testcpy, test, 3);

// 	printf("%s\n%s\n", test, testcpy);
// 	printf("%ld\n", i);
// }