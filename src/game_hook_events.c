/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dateixei <dateixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:36:03 by dateixei          #+#    #+#             */
/*   Updated: 2022/06/25 15:50:58 by dateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 113)
		close_win(game);
	if (keycode == 100 || keycode == 65363)
		player_move_right(game);
	if (keycode == 97 || keycode == 65361)
		player_move_left(game);
	if (keycode == 119 || keycode == 65362)
		player_move_up(game);
	if (keycode == 115 || keycode == 65364)
		player_move_down(game);
	return (0);
}

static int	close_win_hook(t_game *game);
static int	key_hook_event(int keycode, t_game *game);
static int	win_render_hook(t_game *game);

static int	(*hook_close_fn(int (*fn)(t_game *game)))()
{
	union
	{
		int	(*typed)(t_game *game);
		int	(*any)();
	} u;

	u.typed = fn;
	return (u.any);
}

static int	(*hook_key_fn(int (*fn)(int keycode, t_game *game)))()
{
	union
	{
		int	(*typed)(int keycode, t_game *game);
		int	(*any)();
	} u;

	u.typed = fn;
	return (u.any);
}

static int	(*hook_render_fn(int (*fn)(t_game *game)))()
{
	union
	{
		int	(*typed)(t_game *game);
		int	(*any)();
	} u;

	u.typed = fn;
	return (u.any);
}

void	get_hooks(t_game *game)
{
	mlx_hook(game->win.win_ptr, DestroyNotify, NoEventMask,
		hook_close_fn(close_win_hook), game);
	mlx_hook(game->win.win_ptr, KeyPress, KeyPressMask,
		hook_key_fn(key_hook_event), game);
	mlx_loop_hook(game->mlx, hook_render_fn(win_render_hook), game);
}

static int	close_win_hook(t_game *game)
{
	close_win(game);
	return (0);
}

static int	key_hook_event(int keycode, t_game *game)
{
	return (key_hook(keycode, game));
}

static int	win_render_hook(t_game *game)
{
	win_render(game);
	return (0);
}
