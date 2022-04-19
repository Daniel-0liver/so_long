/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/18 23:04:15 by dateixei         ###   ########.fr       */
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
	t_vars			vars;
	t_data			img;
	int				w;
	int				l;
	void	*player;
	void	*wall;
	void	*sand;
	int x;
	int y;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 400, 400);
	img.bits_per_pixel = 100;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
								
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	player = mlx_xpm_file_to_image(vars.mlx, "src/player.xpm", &w, &l);
	wall = mlx_xpm_file_to_image(vars.mlx, "src/wall.xpm", &w, &l);
	sand = mlx_xpm_file_to_image(vars.mlx, "src/sand.xpm", &w, &l);
	x = 0;
	while (x < 400)
	{
		y = 0;
		while (y < 400)
		{
			if (x == 0 || x == 400 || y == 0 || y == 400)
				mlx_put_image_to_window(vars.mlx, vars.win, wall, x, y);
			y += 40;
		}
		x += 40;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, sand, 60, 50);

	mlx_put_image_to_window(vars.mlx, vars.win, player, 60, 40);
	mlx_hook(vars.win, 6, 1L<<6, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}