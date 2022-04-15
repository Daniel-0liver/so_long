/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:37:24 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:14:37 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The calloc() function allocates memory for an array of nmemb elements 
// of size bytes each and returns a pointer
// to the allocated memory.  The memory is set to zero.  If nmemb or 
// size is  0,  then  calloc()  returns  either
// NULL,  or  a  unique  pointer value that can later be successfully 
// passed to free().  If the multiplication of
// nmemb and size would result in integer overflow, then calloc() 
// returns an  error.   By  contrast,  an  integer
// overflow  would  not  be detected in the following call to 
// malloc(), with the result that an incorrectly sized
// block of memory would be allocated:

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocation;

	allocation = malloc(nmemb * size);
	if (!allocation)
		return (0);
	ft_bzero(allocation, (nmemb * size));
	return (allocation);
}

// int main() {
// 	int *test;

// 	return 0;
// }