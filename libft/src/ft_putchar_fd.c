/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:59:24 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/08 14:33:25 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the character ’c’ to the given file
// descriptor.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
