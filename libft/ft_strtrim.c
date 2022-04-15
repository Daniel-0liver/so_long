/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:54:48 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/06 03:26:54 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

int	contain_checker(const char *set, char c)
{
	static int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	size_t	size_copy;
	size_t	start_copy;
	char	*s1_copy;

	if (!s1)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_copy = size_s1;
	start_copy = 0;
	while (contain_checker(set, s1[start_copy]) && start_copy < size_s1)
		start_copy++;
	size_copy--;
	while (contain_checker(set, s1[size_copy]))
		size_copy--;
	if (!(start_copy - size_s1))
		return (ft_strdup(""));
	s1_copy = (char *)malloc(((size_copy - start_copy) + 2) * sizeof(char));
	if (!s1_copy)
		return (NULL);
	size_s1 = 0;
	while (start_copy <= size_copy)
		s1_copy[size_s1++] = s1[start_copy++];
	s1_copy[size_s1] = '\0';
	return (s1_copy);
}
