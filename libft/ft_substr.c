/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:18:00 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/01 23:59:28 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with Malloc and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_return;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		s_return = (char *) malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	else
		s_return = (char *) malloc((len + 1) * sizeof(char));
	if (!s_return)
		return (0);
	while (s[start] && i < len)
		s_return[i++] = s[start++];
	s_return[i] = '\0';
	return (s_return);
}
