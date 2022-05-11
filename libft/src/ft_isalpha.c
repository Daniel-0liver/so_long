/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:47:53 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/10 00:42:21 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// isalpha() checks  for an alphabetic character; in the standard "C" locale, 
// it is equivalent to (isupper(c) || is‐
// lower(c)).  In some locales, there may be additional characters for  which  
// isalpha()  is  true—letters
// which are neither uppercase nor lowercase.

int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c
				>= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
		return (0);
}
