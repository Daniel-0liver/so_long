/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/21 23:05:55 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map_grid[i])
	{
		j = 0;
		while (game->map.map_grid[i][j])
		{
			if (game->map.map_grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
				game->map.wall_img, (TILE_SIZE * j), (TILE_SIZE * i));
			else
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
				game->map.floor_img, (TILE_SIZE * j), (TILE_SIZE * i));
			j++;
		}
		i++;
	}
}

void	player_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->player.player_img, 
	game->player.player_x, game->player.player_y);
}

void	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
}