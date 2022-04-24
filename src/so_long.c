/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 01:36:13 by dateixei          #+#    #+#             */
/*   Updated: 2022/04/24 03:42:14 by dateixei         ###   ########.fr       */
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

int	player_loop(t_game *game)
{
	while (game->player->player_pos_x <= 500)
	{
		game->player->player_pos_x += 10;
		mlx_destroy_image(game->mlx, game->player->player_img);
		game->player->player_img = mlx_xpm_file_to_image(game->mlx, game->player->player_img_path, &game->win->width, &game->win->height);
		mlx_put_image_to_window(game->mlx, game->win->win_ptr, game->player->player_img, game->player->player_pos_x, game->player->player_pos_y);
	}
	return 0;
}

int	main(void)
{
	t_game	game;
	
	game_memory_allocation(&game);
	game.mlx = mlx_init();
	game_init(&game);
	mlx_put_image_to_window(game.mlx, game.win->win_ptr, game.player->player_img, game.player->player_pos_x, game.player->player_pos_y);
	// mlx_key_hook(game.win->win_ptr, key_hook, &game);
	mlx_loop_hook(game.mlx, player_loop, &game);
	mlx_loop(game.mlx);
}