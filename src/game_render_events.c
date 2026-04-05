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

static void	hud_string_put(t_game *game, int x, int y, char *text)
{
	mlx_string_put(game->mlx, game->win.win_ptr, x + 1, y + 1, 0x00111111, text);
	mlx_string_put(game->mlx, game->win.win_ptr, x, y, 0x00FFFFFF, text);
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
	if (now_ms - last_move_ms < 420)
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
	long			now_ms;
	static long	last_anim_ms;
	static int	frame_idx;

	now_ms = get_time_ms();
	if (now_ms - last_anim_ms >= 150)
	{
		frame_idx = (frame_idx + 1) % 2;
		last_anim_ms = now_ms;
	}
	if (frame_idx == 0)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->player.img[0],
			game->player.coord.x, game->player.coord.y);
	if (frame_idx == 1)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->player.img[1],
			game->player.coord.x, game->player.coord.y);
}

void	exit_render(t_game *game)
{
	char	hud[64];
	int	collected;

	if (game->collect.num_c == 0)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->exit.img,
			game->exit.coord.x, game->exit.coord.y);
	mlx_put_image_to_window(game->mlx, game->win.win_ptr, game->step.img,
		0, 0);
	collected = game->collect.total_c - game->collect.num_c;
	snprintf(hud, sizeof(hud), "Moves: %d", game->player.num_moves);
	hud_string_put(game, 20, 24, hud);
	snprintf(hud, sizeof(hud), "Gems: %d/%d", collected, game->collect.total_c);
	hud_string_put(game, 20, 46, hud);
	snprintf(hud, sizeof(hud), "Remaining: %d", game->collect.num_c);
	hud_string_put(game, 20, 68, hud);
}

void	trap_render(t_game *game, int i, int j)
{
	long			now_ms;
	static long	last_anim_ms;
	static int	frame_idx;

	now_ms = get_time_ms();
	if (now_ms - last_anim_ms >= 180)
	{
		frame_idx = (frame_idx + 1) % 2;
		last_anim_ms = now_ms;
	}
	if (frame_idx == 0)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->trap.img[0], (game->size_img * j),
			(game->size_img * i));
	if (frame_idx == 1)
		mlx_put_image_to_window(game->mlx, game->win.win_ptr,
			game->trap.img[1], (game->size_img * j), (game->size_img * i));
}

void	win_render(t_game *game)
{
	trap_update(game);
	map_render(game);
	player_render(game);
	exit_render(game);
}
