/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:35:55 by dateixei          #+#    #+#             */
/*   Updated: 2021/12/05 14:59:24 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function ’f’ to each character of
// the string ’s’ , and passing its index as first
// argument to create a new string (with malloc(3))
// resulting from successive applications of ’f’.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	int		i;

	if (!s)
		return (NULL);
	mapi = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!mapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi[i] = f(i, s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}

// char my_func(unsigned int i, char str)
// {
// printf("My inner function: index = %d and %c\n", i, str);
// return str - 0;
// }

// int main()
// {
// char str[100] = "hello world";
// printf("The str is %s\n", str);
// char *result = ft_strmapi(str, my_func);
// printf("The result is %s\n", result);
// return 0;
// }
