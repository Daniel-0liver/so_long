/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 22:15:12 by dateixei          #+#    #+#             */
/*   Updated: 2021/10/21 22:15:12 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// isprint() checks for any printable character including space.

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
	{
		return (1);
	}
	else
		return (0);
}
