/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 00:20:24 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:33:39 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strrchr() function returns a pointer to the last occurrence of 
// the character c in the string s.

char	*ft_strrchr(const char *s, int c)
{
	char	tmp_c;
	int		size_s;

	tmp_c = c;
	size_s = ft_strlen(s);
	while (*s)
		s++;
	while (size_s > 0)
	{
		if (*s == tmp_c)
			return ((char *)s);
		s--;
		size_s--;
	}
	if (*s == tmp_c)
		return ((char *)s);
	return ((void *)0);
}

// int main() {
// 	char test[] = "testing";
// 	char test2[] = "testing";
// 	char *test_orig;

// 	test_orig = strrchr(test, 't');
// 	char *test_cln = ft_strrchr(test2, 't');
// 	printf("%s, %s\n", test, test_orig);
// 	printf("%s, %s\n", test2, test_cln);
// }