/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:54:01 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/16 19:15:57 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\nKeycode = %d\n", keycode);
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	printf("Hello from mouse_hook!\nMouse Hook x = %d\nMouse Hook y = %d\n", x, y);
	return(0);
}
int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}