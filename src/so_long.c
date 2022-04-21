/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/22 00:52:06 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render_next_frame(t_vars *vars)
// {
// 	t_data	img;

// 	mlx_clear_window(vars->mlx, vars->win);
// 	img.img = mlx_new_image(vars->mlx, 600, 600);
// 	img.bits_per_pixel = 1;
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// }

int	main(void)
{
	t_game	game;
	
	game.mlx = mlx_init();
	window_init(&game);
	mlx_loop(game.mlx);
}