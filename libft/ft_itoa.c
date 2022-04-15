/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:31:48 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/04 00:59:34 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.

int	size_itoa(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= (-1);
		i++;
	}	
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		size;
	int		i;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = size_itoa(n);
	itoa = (char *)malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= (-1);
		itoa[i++] = '-';
	}
	itoa[size] = '\0';
	while (--size >= i)
	{
		itoa[size] = (n % 10) + '0';
		n /= 10;
	}
	return (itoa);
}
