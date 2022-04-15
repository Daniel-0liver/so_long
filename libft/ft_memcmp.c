/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 04:03:41 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:23:30 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memcmp()  function  compares the first n bytes (each interpreted as 
// unsigned char) of the memory areas s1 and s2.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) < *(unsigned char *)(s2 + i))
			return (-1);
		if (*(unsigned char *)(s1 + i) > *(unsigned char *)(s2 + i))
			return (1);
		i++;
	}
	return (0);
}

// int main() {
// 	char test[] = "testing";
// 	char test2[] = "testing";

// 	printf("%d\n", memcmp(test, test2, 5));
// 	printf("%d\n", ft_memcmp(test, test2, 5));

// 	return 0;
// }