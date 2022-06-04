/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:25:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/04 17:48:18 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void ***ptr)
{
	void	**ptr_tmp;

	ptr_tmp = **ptr;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(ptr_tmp);
	*ptr = NULL;
}
