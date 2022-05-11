/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:10:35 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/05 17:56:20 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the string ’s’ to the given file
// descriptor, followed by a newline.

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
