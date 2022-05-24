/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:35:26 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/24 01:17:17 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *game)
{
	map_init(game);
	path_init(game);
	window_init(game);
}

void	window_init(t_game *game)
{
	game->win.width = TILE_SIZE * game->map.map_column;
	game->win.height = TILE_SIZE * game->map.map_row;
	game->win.win_ptr = mlx_new_window(game->mlx,
			game->win.width,
			game->win.height,
			"So_long");
}

void	path_init(t_game *game)
{
	game->map.map_path = "./textures/map.ber";
	game->player.img_path = "./textures/pikach_d1_64.xpm";
	game->floor.img_path = "./textures/floor_64.xpm";
	game->wall.img_path = "./textures/stone_64.xpm";
	game->exit.img_path = "./textures/stair_64.xpm";
}

void	map_init(t_game *game)
{
	map_read(game);
	map_is_rectangular(game);
	game->map.floor_img = mlx_xpm_file_to_image(game->mlx, game->map.floor_path, 
			&game->win.width, &game->win.height);
	game->map.wall_img = mlx_xpm_file_to_image(game->mlx, game->map.wall_path, 
			&game->win.width, &game->win.height);
}
