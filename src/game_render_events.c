/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/02 01:08:11 by dateixei         ###   ########.fr       */
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
					game->wall.img, (game->size_img * j), 
						(game->size_img * i));
			else
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
					game->floor.img, (game->size_img * j), 
						(game->size_img * i));
			if (game->map.map_grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
					game->collect.img, (game->size_img * j), 
						(game->size_img * i));
			j++;
		}
		i++;
	}
}

void	player_render(t_game *game)
{
	if ((game->frames < 150) || (game->frames > 599 && game->frames < 750))
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
			game->player.img[0], 
			game->player.coord.x, game->player.coord.y);
	if ((game->frames > 149 && game->frames < 300) || (game->frames 
		> 449 && game->frames < 600))
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
			game->player.img[1], 
			game->player.coord.x, game->player.coord.y);
	if (game->frames > 299 && game->frames < 450)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, 
			game->player.img[1], 
			game->player.coord.x, game->player.coord.y);
	game->frames++;
	if (game->frames >= 750)
		game->frames = 0;
}

void	exit_render(t_game *game)
{
	if (game->collect.num_c == 0)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->exit.img, 
			game->exit.coord.x, game->exit.coord.y);
}

void	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
	exit_render(game);
}