/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:05:36 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/08 14:24:00 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function f to each character of the
// string passed as argument, and passing its index
// as first argument. Each character is passed by
// address to f to be modified if necessary

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void my_func(unsigned int i, char *str)
// {
// printf("My inner function: index = %d and the string is %s\n", i, str);
// }

// int main()
// {
// char str[100] = "Hello world";
// printf("The result is %s\n", str);
// ft_striteri(str, my_func);
// printf("The result is %s\n", str);
// return 0;
// }