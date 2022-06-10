/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/10 22:15:58 by dateixei         ###   ########.fr       */
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
					game->wall.img, (game->size_img * j), (game->size_img * i));
			else
				mlx_put_image_to_window(game->mlx, game->win.win_ptr,
					game->floor.img, (game->size_img * j), (64 * i));
			if (game->map.map_grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win.win_ptr,
					game->collect.img, (game->size_img * j),
					(game->size_img * i));
			if (game->map.map_grid[i][j] == 'T')
				trap_render(game, i, j);
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
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->step.img,
		0, 0);
	game->step.step_str = ft_itoa(game->player.num_moves);
	mlx_string_put(game->mlx, game->win.win_ptr, 25, 34,
		0x000000FF, game->step.step_str);
	ft_free_ptr((void *)&game->step.step_str);
}

void	trap_render(t_game *game, int i, int j)
{
	if (game->trap.frame < 200 * game->trap.num_t)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->trap.img[0], (game->size_img * j),
			(game->size_img * i));
	if (game->trap.frame > 200 * game->trap.num_t)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->trap.img[1], (game->size_img * j), (game->size_img * i));
	game->trap.frame++;
	if (game->trap.frame >= 400 * game->trap.num_t)
		game->trap.frame = 0;
}

void	win_render(t_game *game)
{
	map_render(game);
	player_render(game);
	exit_render(game);
}
