/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:55:21 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/07 01:10:36 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strdup() function returns a pointer to a new string which is a 
// duplicate of the string s.  Memory for the
// new string is obtained with malloc(3), and can be freed with free(3).

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	int		size;
	int		i;

	size = ft_strlen(s);
	if (!s)
		return (NULL);
	dup_str = (char *)malloc(size + 1 * sizeof(char));
	if (!dup_str)
		return (0);
	i = 0;
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = s[i];
	return (dup_str);
}
