/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:34:39 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/12 00:11:03 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// The strlen() function calculates the length of the string pointed to by s, 
// excluding the terminating null byte ('\0').
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc((size + 1) * sizeof(char));
	if (!s1 || !s2 || !join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[size] = '\0';
	return (join);
}

// The strchr() function returns a pointer to the first occurrence 
// of the character c in the string s.
char	*ft_strchr(const char *s, int c)
{
	char	tmp_c;

	tmp_c = c;
	while (*s)
	{
		if (*s == tmp_c)
			return ((char *)s);
		s++;
	}
	if (*s == tmp_c)
		return ((char *)s);
	return ((void *)0);
}