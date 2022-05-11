/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:50:49 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/07 20:53:04 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	lenght;

	if (!str)
		return (write(1, "(null)", 6));
	lenght = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (lenght);
}
