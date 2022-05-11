/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexadecimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:26:27 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/07 20:52:29 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal_to_hexadecimal(unsigned long d, int index, char x)
{
	int	uper_lower_case;

	uper_lower_case = 87;
	if (x == 'X')
		uper_lower_case = 55;
	if (d > 15)
		index = ft_decimal_to_hexadecimal(d / 16, index, x);
	if ((d % 16) <= 9)
		ft_putchar_fd(((d % 16) + 48), 1);
	else
		ft_putchar_fd((d % 16 + uper_lower_case), 1);
	index += 1;
	return (index);
}
