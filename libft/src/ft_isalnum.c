/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:23:28 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:15:45 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Return 0 if the char isn't alphamumeric and 1 if is.

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c
			<= 'z') || (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
		return (0);
}
