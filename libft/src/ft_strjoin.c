/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:40:03 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/02 01:45:35 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_final;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	s_final = (char *)malloc(size + 1);
	if (!s_final)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		s_final[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < size)
		s_final[i++] = s2[j++];
	s_final[i] = '\0';
	return (s_final);
}
