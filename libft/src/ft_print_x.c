/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:57:58 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/07 20:53:17 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int d, char c)
{
	int		lenght;

	if (!d)
		return (write(1, "0", sizeof(char) * 1));
	lenght = ft_decimal_to_hexadecimal(d, 0, c);
	c = c + 1;
	return (lenght);
}
