/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 02:58:29 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:31:36 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strncmp() function is similar, except it compares only the 
// first (at most) n bytes of s1 and s2.

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
// int main() {
// 	char s1[] = "s1 string";
// 	char s2[] = "s2 string";
// 	int orig;
// 	int ft;
// 	printf("%d\n", orig = strncmp(s1, s2, 2));
// 	printf("%d\n", ft = ft_strncmp(s1, s2, 2));
// 	return 0;
// }