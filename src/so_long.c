/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/16 19:24:58 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_vars			vars;
	t_data			img;
	int				x;
	int				y;
	int	color;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 600, 600);
	img.bits_per_pixel = 100;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	x = 300;
	y = 100;
	color = 1;
	while (x > 1 && y < 400)
	{
		my_mlx_pixel_put(&img, x, y, color);
		my_mlx_pixel_put(&img, x+1, y+1, color);
		x++;
		y++;
		color = rand();
	}
	x = 300;
	y = 100;
	while (x > 1 && y < 400)
	{
		my_mlx_pixel_put(&img, x, y, color);
		my_mlx_pixel_put(&img, x-1, y-1, color);
		x--;
		y++;
		color = rand();
	}
	while (x < 600)
	{
		my_mlx_pixel_put(&img, x, y, color);
		my_mlx_pixel_put(&img, x-1, y-1, color);
		x++;
		color = rand();
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, "player.xpm", 26, 32);
	mlx_loop(vars.mlx);
}