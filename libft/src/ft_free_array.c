/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:25:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/04 14:46:17 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void ***ptr)
{
	int		i;
	void	**ptr_tmp;

	i = 0;
	ptr_tmp = **ptr;
	while (ptr_tmp[i])
	{
		free(ptr_tmp[i]);
		i++;
	}
	free(**ptr);
	**ptr = NULL;
}
