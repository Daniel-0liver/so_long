/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:01:41 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/08 14:09:04 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The atoi() function converts the initial portion of 
// the string pointed to by nptr to int.

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sing;

	i = 0;
	sing = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == '\f' || nptr[i] == ' ' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v'))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sing *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sing);
}

// int main () {
// 	char test[] = "  	-2147483649hello";

// 	printf("%d\n", atoi(test));
// 	printf("%d\n", ft_atoi(test));

// 	return 0;
// }