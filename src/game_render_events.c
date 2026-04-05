/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:34:46 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/12 23:44:53 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	trap_update(t_game *game)
{
	int	index;
	int	next_x;
	int	next_y;
	int	player_x;
	int	player_y;
	char	next_tile;
	long	now_ms;
	static long	last_move_ms;

	if (game->trap.num_t <= 0)
		return ;
	player_x = game->player.coord.x / game->size_img;
	player_y = game->player.coord.y / game->size_img;
	now_ms = get_time_ms();
	if (now_ms - last_move_ms < 280)
		return ;
	last_move_ms = now_ms;
	index = 0;
	while (index < game->trap.num_t)
	{
		next_y = game->trap.coord[index].y;
		next_x = game->trap.coord[index].x + game->trap.dir[index];
		next_tile = game->map.map_grid[next_y][next_x];
		if (next_tile != '0')
		{
			game->trap.dir[index] *= -1;
			next_x = game->trap.coord[index].x + game->trap.dir[index];
			next_tile = game->map.map_grid[next_y][next_x];
		}
		if (next_tile == '0')
		{
			game->map.map_grid[game->trap.coord[index].y]
			[game->trap.coord[index].x] = '0';
			if (next_x == player_x && next_y == player_y)
				error_event("You missed!!!", game, 0);
			game->trap.coord[index].x = next_x;
			game->map.map_grid[next_y][next_x] = 'T';
		}
		index++;
	}
}

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
	char	hud[64];

	if (game->collect.num_c == 0)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->exit.img,
			game->exit.coord.x, game->exit.coord.y);
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->step.img,
		0, 0);
	snprintf(hud, sizeof(hud), "Moves: %d", game->player.num_moves);
	mlx_string_put(game->mlx, game->win.win_ptr, 20, 24, 0x000000FF, hud);
	snprintf(hud, sizeof(hud), "Collect left: %d", game->collect.num_c);
	mlx_string_put(game->mlx, game->win.win_ptr, 20, 46, 0x000000FF, hud);
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
	trap_update(game);
	map_render(game);
	player_render(game);
	exit_render(game);
}
