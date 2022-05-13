/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:35:26 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/13 00:56:19 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_game *game)
{
	window_init(game);
	player_init(game);
	map_init(game);
}

void	game_memory_allocation(t_game *game)
{
	game->player.player_posit = ft_calloc(1, sizeof(t_posit));
}

void	window_init(t_game *game)
{
	game->win.height = 500;
	game->win.width = 500;
	game->win.win_ptr = mlx_new_window(game->mlx, game->win.height, game->win.width, "teste");
}

void	player_init(t_game *game)
{
	game->player.player_img_path = "./src/player.xpm";
	game->player.player_posit->x = 10;
	game->player.player_posit->y = 10;
	game->player.player_img = mlx_xpm_file_to_image(game->mlx, game->player.player_img_path, &game->win.width, &game->win.height);
}

void	map_init(t_game *game)
{
	game->map.map_path = "./src/map.ber";
	map_read(game);
}