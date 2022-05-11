/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:51:47 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/08 14:24:19 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If  c is a lowercase letter, toupper() returns its uppercase 
// equivalent, if an uppercase representation exists in the 
// current locale.  Otherwise, it returns c.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
