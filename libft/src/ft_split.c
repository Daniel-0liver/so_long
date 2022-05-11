/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:45:54 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/06 03:30:52 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must be
// ended by a NULL pointer.

static size_t	get_size_array(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	*split = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	split = (char **) malloc((get_size_array(s, c) + 1) * sizeof(char *));
	i = 0;
	if (!split)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j != 0)
			split[i++] = ft_substr(s, 0, j);
		if (j != 0 && !split[i - 1])
			return (free_split(split));
		s += j;
	}
	split[i] = NULL;
	return (split);
}
