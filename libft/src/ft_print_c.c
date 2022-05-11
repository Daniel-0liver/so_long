/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 03:01:56 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/03 03:02:50 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(char c)
{
	int	lenght;

	lenght = 1;
	write(1, &c, sizeof(char));
	return (lenght);
}
