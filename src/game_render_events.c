/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/05/27 01:06:50 by dateixei         ###   ########.fr       */
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
				game->wall.img, (TILE_SIZE * j), (TILE_SIZE * i));
			else
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
				game->floor.img, (TILE_SIZE * j), (TILE_SIZE * i));
			if (game->map.map_grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
				game->collect.img, (TILE_SIZE * j), (TILE_SIZE * i));
			j++;
		}
		i++;
	}
}

void	player_render(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->player.img, 
	game->player.coord.x, game->player.coord.y);
}

void	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
}